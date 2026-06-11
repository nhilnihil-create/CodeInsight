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
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cout << setprecision(12) << fixed;
        cin >> n;
        ll ans = 0;
        ll X = 0;
        ll Y = 0;
        for(ll i=0;i<n;i++) {
                ll u,vv;
                cin >> u >> vv;
                v.pb(make_pair(u, vv));
                X += u;
                Y += vv;
                ans = max(ans , f(X, Y));
        }
        ll itr = 100005;
        while(itr--){
                X=0; Y=0;
                shuffle(v.begin(), v.end(), rng);
                for(ll i=0;i<n;i++){
                        //X += v[i].first; Y += v[i].second;
                        //ans=max(ans, f(X, Y));
                        if(f(X+v[i].first , Y + v[i].second) > f(X , Y)) {
                                X += v[i].first; Y += v[i].second;
                        }
                        ans= max(ans, f(X, Y));
                }
        }
        ld aa = 1.0*ans; aa = (ld)sqrt(aa);
        cout << aa << endl;
        return 0;
}
