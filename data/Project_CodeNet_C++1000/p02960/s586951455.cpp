#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define int long long
#define swap(x,y) (x^=y^=x^=y)

#define debug1(a) cerr<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

using namespace std;
 
#define mod 1000000007
long long modexpo(long long x, long long p){
    int res = 1;x = x%mod;
    while(p){
        if(p%2)res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}

struct compare{
    bool operator() (const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};

//seen editorial, digit DP

const int nax = 1e5 + 5;

// state
// dp[ith digit of number][rem mod 13]

int dp[nax][13];
string s;

int32_t main(){
    IOS
    int n;
    cin >> s;
    n = s.length();
    
    //base case we say that 0 mod 13 = 1 therefore initial state
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        int c = -1;
        if(s[i] != '?'){
            c = (int)(s[i] - '0');
        }
        for(int j = 0; j < 10; j++){
            // s[i] is fixed value we take that else iterate over all possible values
            if(c != -1 && c != j){
                continue;
            }
            // rem can be between 0-12 inclusive
            for(int rem = 0; rem < 13; rem++){
                // transition : IMP
                // if i use j at this i, then whatever num i have till now will be multiplied by 10
                // then add j to it, take mod 13, this newly formed number will only be affected by
                // rem which we already have for particular i,
                // thus rem*10 + j mod 13 forms next rem for current rem.

                dp[i+1][(rem*10 + j)%13] += dp[i][rem];
                
            }
        }
        for(int j = 0; j < 13; j++){
            dp[i+1][j] %= mod;
        }
    }
    int res = dp[n][5];
    res %= mod;
    cout << res << "\n";
}