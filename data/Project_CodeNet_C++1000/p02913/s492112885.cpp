#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

vec zalgo(string& s) {
    int n = s.size();
    vec A(n);
    A[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < n && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
    return A;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;

    rep(i, n) {
        string t = s.substr(i);
        auto lcp = zalgo(t);

        rep(j, t.size()) {
            int l = min(lcp[j], j);
            res = max(l, res);
        }
    }

    cout << res << endl;
    return 0;
}