#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0;
    if (p ==  2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0')%p == 0) ans += i + 1;
        }
    }
    else {
        map<ll,ll> cnt;
        cnt[0]++;
        ll num = 0, ten = 1;
        for (int i = n - 1; i >= 0; i--) {
            num = num + (s[i] - '0') * ten;
            ten *= 10;
            ten %= p;
            num %= p;
            cnt[num]++;
        }
        for (auto x:cnt) {
            ans += x.second * (x.second - 1) / 2;
        }
    }
    cout << ans << "\n";
}
