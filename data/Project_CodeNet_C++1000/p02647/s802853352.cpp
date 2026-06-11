#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod = 1e9 + 7;

int main() {
	ll n,k;
    cin >> n >> k;
    vector<ll> prev(n);
    rep(i, n) cin >> prev[i];
    vector<ll> current(n);
    rep(_, k) {
        vector<ll> sums(n + 1, 0);
        const auto& source = prev;
        for (int i = 0; i < n; i++) {
            auto t = source[i];
            auto front = max(0LL, i - t);
            auto back = min(n, i + t + 1);
            sums[front]++;
            sums[back]--;
        }
        //cout << "back array" << endl;
        //rep(i, n + 1) {
        //    cout << sums[i] << ",";
        //}
        //cout << endl;
        ll s = 0;
        //cout << "current" << endl;
        rep(i, n) {
            s += sums[i];
            //cout << s << ",";
            current[i] = s;
        }
        bool finish = true;
        rep(i, n) {
            if (current[i] != n) {
                finish = false;
                break;
            }
        }
        swap(prev, current);
        if (finish) break;
    }
    rep(i, n) {
        cout << prev[i] << " ";
    }
    cout << endl;
	return 0;
}
	