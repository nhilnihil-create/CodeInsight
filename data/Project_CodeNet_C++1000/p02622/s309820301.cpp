#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll ans = 0;
    string s, t;
    cin >> s >> t;
    rep(i, s.size())
    {
        if (s[i] != t[i]) ans++;
    }
	
    cout << ans << "\n";

    return 0;
}