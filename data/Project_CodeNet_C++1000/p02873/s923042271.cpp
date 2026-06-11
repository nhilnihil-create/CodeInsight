#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
typedef long long ll;

ll n, ans;
vector<ll> v;
string s;
int main() {
    cin >> s;
    ll now = 1;
    v.push_back(0);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            v.push_back(now);
            ans += (now) * (now - 1) / 2;
            now = 1;
        } else {
            now++;
        }
    }
    v.push_back(now);
    v.push_back(0);
    ans += (now) * (now - 1) / 2;
    if (s[0] == '<') {
        for (int i = 1; i < v.size() - 1; i += 2) {
            ans += max(v[i], v[i + 1]);
        }
    } else {
        for (int i = 0; i < v.size() - 1; i += 2) {
            ans += max(v[i], v[i + 1]);
        }
    }
    cout << ans << endl;
}