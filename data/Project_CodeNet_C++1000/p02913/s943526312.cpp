#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

vector<int> z_algorithm(string &s) {
    vector<int> z(s.size(), 0);
    z[0] = s.size();

    int i = 1, j = 0;
    while (i < (int)s.size()) {
        while (i + j < (int)s.size() && s[j] == s[i + j]) j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }

        int k = 1;
        while (k < j && k + z[k] < j) {
            z[i + k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}

int main() {
    int N; string S; cin >> N >> S;

    int ans = 0;
    REP(i, 0, S.size()) {
        string t = S.substr(i);
        auto z = z_algorithm(t);
        REP(j, 0, z.size()) {
            if (i + z[j] > i + j) continue;
            ans = max(ans, z[j]);
        }
    }
    cout << ans << endl;
    return 0;
}