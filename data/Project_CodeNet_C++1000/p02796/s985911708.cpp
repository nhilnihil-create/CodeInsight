#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n; cin >> n;
    ll x[n], l[n];
    rep(i, n)
    {
        cin >> x[i] >> l[i];
        int d = l[i];
        l[i] = l[i] + x[i];
        x[i] = x[i] - d;
        if (x[i] < 0) x[i] = 0;
    }

    Pl itv[n];
    rep(i, n) itv[i].first = l[i], itv[i].second = x[i];
    sort(itv, itv + n);

    ll ans = 0, t = 0;
    rep(i, n)
    {
        if (t <= itv[i].second)
        {
            //cout << itv[i].first << endl;
            ans++;
            t = itv[i].first;
        }
    }
    cout << ans << endl;
}