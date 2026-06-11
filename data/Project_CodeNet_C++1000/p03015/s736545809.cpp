#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
string s;
ll ans;
ll d[300005];

int main()
{
    cin>>s;
    d[0] = 1;
    for(ll i = 1; i <= s.size(); i++)
    {
        d[i] = d[i - 1] * 3 % M;
    }
    ll now = 1;
    for(ll i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') ans += d[(ll)s.size() - i - 1] * now % M, ans %= M, now *= 2;
        now %= M;
    }
    ans += now;
    ans %= M;
    cout<<ans<<endl;
    return 0;
}
