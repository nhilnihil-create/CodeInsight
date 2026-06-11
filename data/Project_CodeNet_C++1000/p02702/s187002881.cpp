#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

string S;
int mem[3000];
int ans, mod = 2019;

signed main()
{
    cin >> S;
    reverse(S.begin(), S.end());

    int now = 0, tmp = 1;
    mem[0] = 1;
    for(auto e : S)
    {
        now = (now + (e - '0') * tmp) % mod;
        ans += mem[now];
        mem[now]++;
        tmp = (tmp * 10) % mod;
    }

    cout << ans << endl;
}
