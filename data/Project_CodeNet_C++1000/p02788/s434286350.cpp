#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        int n, d, a;
        cin >> n >> d >> a;

        vector<pair<ll, ll>> p(n);
        REP(i, n) {
                cin >> p[i].first >> p[i].second;
        }

        sort(p.begin(), p.end());

        vector<ll> x(n), h(n);
        REP(i, n) {
                x[i] = p[i].first;
                h[i] = (p[i].second + a - 1) / a;
        }

        vector<int> reach(n);
        for (int l = 0, r = 0; l < n; l++) {
                while (r < n && x[r] - x[l] <= 2 * d) {
                        r++;
                }
                reach[l] = r;
        }

        ll ans = 0, cur = 0;
        vector<ll> m(n + 1, 0);
        REP(i, n) {
                cur -= m[i];

                ll t = max(0LL, h[i] - cur);
                ans += t;

                cur += t;
                m[reach[i]] += t;
        }

        cout << ans << endl;
        
        return 0;
}
