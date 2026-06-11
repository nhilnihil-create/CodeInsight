#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
    
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<long long> pos, po(s.size());
    po[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] & 1) {
            pos.push_back(i);
        }
        if (i > 0) {
            po[i] = (po[i-1] * 3) % MOD;
        }
    }
    long long ans = 0, two = 1;
    reverse(pos.begin(), pos.end());
    for (int x : pos) {
        ans = (ans + (two * po[x]) % MOD) % MOD;
        two = (two * 2ll) % MOD;
    }
    cout << (ans + two) % MOD;
    return 0;
}