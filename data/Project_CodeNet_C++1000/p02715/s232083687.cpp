
// Problem : E - Sum of gcd of Tuples (Hard)
// Contest : AtCoder - AtCoder Beginner Contest 162
// URL : https://atcoder.jp/contests/abc162/tasks/abc162_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n,k;

int binpow(int x,int y){
    x %= mod;
    int res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>k;
    vi ans(k+1);
    int res = 0;
    for(int i=k;i>=1;i--){
        ans[i] = binpow(k/i,n);
        for(int j=2*i;j<=k;j+=i) ans[i] = (ans[i]-ans[j]+mod)%mod;
        res = (res + (ans[i]*i)%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}
