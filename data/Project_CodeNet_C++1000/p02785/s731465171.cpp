#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    ll n, k;cin >> n >> k;
    vector<ll> h(n);rep(i,n)cin >> h[i];
    sort(h.rbegin(),h.rend());
    ll ans = 0;
    if(n<=k)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        ans += h[i];
    }
    
    cout << ans << endl;
}