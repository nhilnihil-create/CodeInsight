#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    vector<ll> c(26);
    vector<vector<ll> > v(26);

    for(ll i = 0; i < s.length(); i++) {
        ll a = s[i] - 'a';
        c[a]++;
        v[a].push_back(i);
    }

    for(ll i = 0; i < t.length(); i++) {
        ll a = t[i] - 'a';
        if(c[a] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<vector<ll> > n(26, vector<ll>(s.length()));

    for(ll i = 0; i < 26; i++) {
        if(c[i])
            n[i][0] = v[i][0];
    }

    vector<ll> b(26);

    ll x = s[0] - 'a';
    b[x]++;
    b[x] %= c[x];
    n[x][0] = v[x][b[x]];

    for(ll i = 1; i < s.length(); i++) {
        for(ll j = 0; j < 26; j++) {
            n[j][i] = n[j][i - 1];
        }
        ll a = s[i] - 'a';
        b[a]++;
        b[a] %= c[a];
        n[a][i] = v[a][b[a]];
    }

    ll pos = 0;
    ll ans = 0;

    x = 0;
    if(t[0] == s[0]) x++;

    for(ll i = x; i < t.length(); i++) {
        ll a = t[i] - 'a';
        ll next = n[a][pos];
        if(next <= pos) {
            ans += static_cast<ll>(s.length());
        }
        pos = next;
    }

    cout << ans + pos + 1LL << endl;
}