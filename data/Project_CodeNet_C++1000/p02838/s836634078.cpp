#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

// #define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
using P = pair<int, int>;

vector<int> to[100005];
int cost[100005];
signed main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];
    long long ans = 0;
    rep(i,60) {
        long long x = 0;
        rep(j, n) {
             if(a[j]>>i&1) ++x;
        }
        //cout << x << endl;
        long long tmp = x*(n-x)%mod;
        rep(j, i) tmp = tmp*2%mod;
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;


    return 0;
}

