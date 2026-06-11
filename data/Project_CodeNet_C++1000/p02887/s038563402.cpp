#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
const int mod = 1000000007;

int main() {
    ll n;
    string s;
    cin >> n >> s;

    ll cnt = 0;
    for(ll i = 0; i < n - 1; i++) {
        char now = s[i];
        if(s[i] == s[i + 1]) {
            cnt++;
        }
    }

    cout << n - cnt << endl;

    return 0;
}