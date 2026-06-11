#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <ll, pair <ll, ll>>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >
 
typedef long long ll;
 
typedef long double ld;
 
using namespace std;
 
const ll maxn = 1e6 + 100;

ll n, m, k, t;

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    string s;
    cin >> s;
    n = s.length();
    // cout << n << endl;
    ll ans = 0;
    // set <string> S;
    string last = "";
    string cur = "";
    // S.insert(cur);
    for (q = 0; q < n; q++) {
        if (cur == last) {
            cur += s[q]; 
        }
        else {
            last = cur;
            // S.insert(cur);
            ans++;
            cur = "";
            cur += s[q];
        }
    }
    if (last != cur) {
        ans++;
    }
    cout << ans;
    return 0;
}
