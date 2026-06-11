#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    vector<int > v;
    for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) v.push_back(i);
    int ans = v.size();
    cout << ans << '\n';
    return 0;
}
