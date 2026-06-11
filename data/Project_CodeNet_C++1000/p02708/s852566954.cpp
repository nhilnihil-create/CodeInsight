#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;


int main(){
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    ll minv = 0, maxv = 0;
    for(int i=0; i<=n; i++){
        maxv += n-i;
        minv += i;
        if(i >= k-1) ans = (ans + (maxv - minv + 1)) % MOD;
    }

    cout << ans << endl;
}