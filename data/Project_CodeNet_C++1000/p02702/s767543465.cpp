#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 2019;

int main() {
    string S; cin >> S;
    reverse(S.begin(), S.end());
    int N = S.size();
    int total = 0;
    vector<int> cnt(mod);
    int x = 1;
    int ans = 0;
    rep(i, N){
        cnt[total]++;
        int a = S[i] - '0';
        a *= x;
        a %= mod;
        total += a;
        total %= mod;
        ans += cnt[total];

        x *= 10;
        x %= mod;
    }

    cout << ans << endl;

    return 0;
}