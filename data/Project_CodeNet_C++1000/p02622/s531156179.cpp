#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i]!=t[i]) ans++;
    }
    cout << ans << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
