#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    while(1) {
        ll n;
        cin >> n;
        if(!n) break;
        vector<tuple<ll,ll,ll,ll>> v(2*n);
        for(ll i=0; i<n; i++) {
            string s;

            cin >> s;
            s[2] = s[5] = '\0';
            ll x, y, z;
            tie(x, y, z) = make_tuple(atoll(s.c_str()), atoll(s.c_str()+3), atoll(s.c_str()+6));
            v[2*i+0] = make_tuple(x,y,z,1);

            cin >> s;
            s[2] = s[5] = '\0';
            tie(x, y, z) = make_tuple(atoll(s.c_str()), atoll(s.c_str()+3), atoll(s.c_str()+6));
            v[2*i+1] = make_tuple(x,y,z,-1);
        }

        sort(v.begin(), v.end());

        ll res = 0, s = 0;
        for(auto &t: v) {
            ll x, y, z, w;
            tie(x, y, z, w) = t;
            s += w;
            res = max(res, s);
        }
        cout << res << endl;
    }
}

