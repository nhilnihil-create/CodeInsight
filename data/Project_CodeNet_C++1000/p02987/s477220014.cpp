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

// long long modexpo(long long x, long long p){
//     int res = 1;x = x%mod;
//     while(p){
//         if(p%2)res = res * x;
//         p >>= 1;
//         x = x*x % mod;
//         res %= mod;
//     }
//     return res;
// }

// int max(int a,int b){return (a>b?a:b);} 
// int min(int a,int b){return (a<b?a:b);}


struct compare{
    bool operator() (const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};

void yes(){
    cout << "Yes" << endl;
}

int32_t main(){
    IOS
    string s;
    cin >> s;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                continue;
            }
            for(int k = 0; k < 4; k++){
                if(k == i || k == j){
                    continue;
                }
                for(int l = 0; l < 4; l++){
                    if(l == i || l== j || l == k){
                        continue;
                    }
                    if(s[i] == s[j] && s[k] == s[l] && s[i] != s[k]){
                        cout << "Yes" << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    cout << "No" << endl;
} 