#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;
typedef long double ld;


ll n;
vector< pll > v;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll f(ll X, ll Y)
{
        return (X*X + Y*Y);
}
ld g(pll X, pll Y)
{
        if(Y.first == 0 && Y.second == 0) return 0;
        ld m1 = f(X.first, X.second);
        ld m2 = f(Y.first, Y.second);
        return (ld)(((ld)(X.first*Y.first + X.second*Y.second)) / (m1 * m2));
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cout << setprecision(12) << fixed;
        cin >> n;
        ll ans = 0;
        ll X=0; ll Y=0;
        for(ll i=0;i<n;i++) {
                ll u,vv;
                cin >> u >> vv;
                v.pb(make_pair(u, vv));
                X += u;
                Y += vv;
                ans = max(ans , f(X, Y));
        }
        for(ll i=0;i<n;i++) {
                pll A = v[i];
                if(A.first==0 && A.second == 0) continue;
                vector< pair<ld, ll> > t;
                for(ll j=0;j<n;j++) {
                        t.pb(make_pair(g(A, v[j]), j));
                }
                sort(t.rbegin(), t.rend());
                ll X = 0;
                ll Y = 0;
                for(auto &j : t){
                        ll id = j.second;
                        if(f(X + v[id].first, Y + v[id].second) > f(X , Y)) {
                                X += v[id].first; Y += v[id].second;
                        }
                        ans = max(ans, f(X , Y));
                }
        }
        ld aa = ans; aa = sqrt(aa);
        cout << aa << endl;
        return 0;
}
