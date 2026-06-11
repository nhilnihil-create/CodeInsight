#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    int n;
    cin >> n;
    db ans = 0;
    vector<tuple<double, ll, ll>> v(0);
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        if (!x && !y)
        {
            continue;
        }

        tuple<double, ll, ll> a = make_tuple(atan2(x, y), x, y);
        v.pb(a);
    }

    sort(all(v));
    /*rep(i,siz(v)){
        cout<<get<1>(v[i])<<" "<<get<2>(v[i])<<endl;
    }*/

    for (int i = 0; i < siz(v); i++)
    {
        for (int j = i; j < 2*siz(v); j++)
        {
            if(siz(v)<=j-i)continue;

            double x = 0, y = 0;
            for (int k = i; k <= j; k++)
            {
                x += get<1>(v[k%siz(v)]);
                y += get<2>(v[k%siz(v)]);
                //cout<<x<<" "<<y<<endl;
                
            }
            //cout<<i<<" "<<j<<" "<<x*x+y*y<<endl;
            ans = max(ans, x * x + y * y);
        }
    }

    cout << fixed << setprecision(20) << sqrt(ans) << endl;
}
