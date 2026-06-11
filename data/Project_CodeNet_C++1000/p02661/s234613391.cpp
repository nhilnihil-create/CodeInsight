#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define pb(a) push_back(a)
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}


int main()
{
    int n;cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    REP(i,n){
        cin >> a[i] >> b[i];
    }
    sort(all(a));sort(all(b));
    if(n%2==1){
        cout << b[(n + 1) / 2 - 1] -a[(n + 1) / 2 - 1] + 1 << endl;
    }
    else{
        double tmp = double(b[n / 2 - 1] + b[n / 2])/2 - double(a[n / 2 - 1] + a[n / 2]) / 2;
        ll ans=tmp/0.5+1;
        cout << ans << endl;
    }
}
