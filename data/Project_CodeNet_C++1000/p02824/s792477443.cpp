#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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
        ll n, m, v, p;
        cin >> n >> m >> v >> p;

        vector<ll> a(n);
        rep (i, n) cin >> a[i];

        sort(a.begin(), a.end(), greater<ll>());

        auto check = [&](int x) {
                if (x < p) {
                        return true;
                }

                if (a[x] + m < a[p-1]) {
                        return false;
                }

                ll s = 0;
                rep (i, n) {
                        if (i < p-1) {
                                s += m; 
                        } else if (i < x) {
                                s += a[x] + m - a[i]; 
                        } else {
                                s += m;
                        }
                }

                return s >= m * v;
        };

        int l = 0, r = n;
        while (r - l > 1) {
                int m = (l + r) / 2;
                if (check(m)) {
                        l = m;  
                } else {
                        r = m;
                }
        }

        cout << l + 1 << endl;

        return 0;
}
