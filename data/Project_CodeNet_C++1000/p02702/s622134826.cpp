#include <bits/stdc++.h>
#define long long long int
static const int MOD = 2019;
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int c = 0;
    
    int inv10 = 1;
    while ((inv10 * 10) % MOD != 1) inv10++;
    
    int p10 = 1;
    vector<int> cnt(MOD);
    cnt[0]++;
    long res = 0;
    for (int i = 0; i < n; i++) {
        c = (c * 10 + (s[i] - '0')) % MOD;
        p10 = (p10 * inv10) % MOD;
        int x = (c * p10) % MOD;
        res += cnt[x];
        cnt[x]++;
    }
    cout << res << "\n";

    return 0;
}