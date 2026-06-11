#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

const ll mod = 1e9 + 7;

ll mylcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    ll g = 1, mem, tmp;
    vll a(n);
    REP(i, n) {
        cin >> a[i];
        g = mylcm(g, a[i] / 2);
        if (g > m) {
            cout << 0 << endl;
            return 0;
        }
        tmp = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            tmp++;
        }
        if (i && tmp != mem) {
            cout << 0 << endl;
            return 0;
        }
        mem = tmp;
    }

    ll res = (m - g) / (2 * g) + 1;
    cout << res << endl;
    return 0;
}