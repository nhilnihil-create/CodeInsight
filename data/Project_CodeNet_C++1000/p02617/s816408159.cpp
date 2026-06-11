#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    ll n;
    cin >> n;
    ll ans = (n*(n+1)*(n+2))/6;
    rep(i,n-1){
        ll u,v;
        cin >> u >> v;
        if(u>v) swap(u,v);
        --u;--v;
        ans -= (u+1)*(n-v);
    }
    cout << ans << endl;
    return 0;
}