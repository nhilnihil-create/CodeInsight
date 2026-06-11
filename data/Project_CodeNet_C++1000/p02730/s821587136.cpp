#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string s1 = s;
    reverse(all(s1));
    if (s != s1) {
        cout << "No";
        return 0;
    }
    int n = s.size();
    string t = s.substr(0, (n - 1) / 2);
    string t1 = t;
    reverse(all(t1));
    if (t != t1) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
