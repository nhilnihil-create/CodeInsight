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
const int mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

int main() {
    string s;
    cin >> s;
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No");
    return 0;
}
