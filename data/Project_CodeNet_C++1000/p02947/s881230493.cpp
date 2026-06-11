#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, ans = 0;
    vector<string> s;
    cin >> n;
    rep(i, n)
    {
        string tmp;
        cin >> tmp;
        sort(tmp.begin(), tmp.end());
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());
    ll cnt = 0;
    rep(i, n - 1)
    {
        if (s[i].compare(s[i + 1]) == 0)
        {
            ans += cnt + 1;
            cnt++;
        }
        else
            cnt = 0;
    }
    // rep(i, n) cout << s[i] << endl;
    cout << ans << endl;
    return 0;
}