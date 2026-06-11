//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10000 + 10;

ll cnt[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0;
    if (p == 2 || p == 5){
        for (ll i = 0; i < n; i ++)
            if ((s[i] - '0') % p == 0)
                ans += i + 1;
        return cout << ans, 0;
    }
    cnt[0] = 1;
    ll cur = 0, pw = 1;
    for (ll i = n - 1; i >= 0; i --){
        cur = (cur + (s[i] - '0') * pw) % p;
        ans += cnt[cur];
        cnt[cur] ++;
        pw = pw * 10 % p;
    }
    cout << ans;
    return 0;
}
