#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

int main()
{
    string L; cin >> L;
    int len = L.size();

    vector<int> x3(len);
    x3[0] = 1;
    for (int i = 1; i < x3.size(); i++) {
        x3[i] = (ll)x3[i-1] * 3 % MOD;
    }

    ll ans_eq = 1, ans_lt = 0;
    for (int i = 0; i < len; i++) {
        if (L[i] == '1') {
            ans_lt = (ans_lt + (ans_eq * x3[len - i - 1] % MOD)) % MOD;
            ans_eq = (ans_eq * 2) % MOD;
        }
    }
    ll ans = (ans_eq + ans_lt) % MOD;
    cout << ans << endl;
}
