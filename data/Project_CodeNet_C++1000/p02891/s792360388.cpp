#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S;
    ll K;
    cin >> S >> K;
    vector<pair<char, ll>> v;
    S.push_back('.');
    ll cnt = 0;
    char cur = S[0];
    for (int i = 0; i < S.size(); i++) {
        if (cur == S[i]) cnt++;
        else {
            v.push_back(make_pair(cur, cnt));
            cur = S[i];
            cnt = 1;
        }
    }

    if (v.size() == 1) { cout << (v[0].second * K) / 2 << '\n'; }
    else {
        ll ans = 0;
        for (auto p : v) ans += (p.second / 2) * K;
        pair<char, int> pl = *v.begin(), pr = *v.rbegin();
        if (pl.first == pr.first) {
            ans -= (K - 1) * (pl.second / 2 + pr.second / 2);
            ans += (K - 1) * ((pl.second + pr.second) / 2);
        }
        cout << ans << '\n';
    }
}
