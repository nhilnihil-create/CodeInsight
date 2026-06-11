#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 1e4 + 5;
ll n, p, ans, cnt[N];
string s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p >> s;
    if(p == 2 || p == 5)
    {
        for(int i = 0;i < n;++i)
            if((s[i] - '0') % p == 0)
                ans += (i + 1);
    }
    else
    {
        reverse(s.begin(), s.end());
        ll cum = 0, ten = 1;
        ++cnt[0];
        for(int i = 0;i < n;++i)
            ans += cnt[(cum += (s[i] - '0') * ten) %= p]++, (ten *= 10) %= p;
    }
    cout << ans;
    return 0;
}
