#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t, last;
    cin >> s;
    int i = 0;
    vector<string>ans;
    while(i < s.size())
    {
        t += s[i++];
        if(t == last)
            continue;
        last = t;
        ans.push_back(t);
        t = "";
    }
    cout << ans.size();
    return 0;
}
