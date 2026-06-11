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

// int max(int a,int b){return (a>b?a:b);} 
// int min(int a,int b){return (a<b?a:b);}


struct compare{
    bool operator() (const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};

const int nax = 2e3 + 5;
int fib[nax], inv[nax];

int nCk(int n, int k){
    if(k > n){
        return 0;
    }
    int temp = fib[n];
    temp *= inv[k];
    temp %= mod;
    temp *= inv[n-k];
    temp %= mod;
    return temp;
}

int32_t main(){
    IOS
    fib[0] = inv[0] = 1;
    fib[1] = inv[1] = 1;
    for(int i = 2; i < nax; i++){
        fib[i] = fib[i-1]*i;
        fib[i] %= mod;
        inv[i] = modexpo(fib[i], mod-2);
    }
    int n,k;
    cin >> n >> k;
    int slots = n-k+1;
    // debug3(p,q, slots);
    for(int i = 1; i <= k; i++){
        int x = nCk(k-1,i-1);
        // cout << x << endl;
        int y = nCk(slots,i);
        x *= y;
        x %= mod;
        cout << x << endl;
    }
} 