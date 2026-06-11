#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl;
const int MOD = 2019;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    map<int, int> cnt;
    cnt[0]=1;
    int n = s.size();
    ll num = 0;
    ll mult = 1;
    ll ans = 0;
    for (int i = n-1; i>= 0; i--) {
        num += mult*(s[i]-'0'); num %= MOD;
        ans += cnt[num];
        cnt[num]++;
        mult = mult*10 % MOD;
    }
    cout << ans << endl;

    return 0;
}
