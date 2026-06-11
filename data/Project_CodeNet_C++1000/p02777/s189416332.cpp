#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    map<string, int> mp;
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    mp[s] = a;
    mp[t] = b;
    string u;
    cin >> u;
    mp[u]--;
    cout << mp[s] << " " << mp[t] << endl;
    return 0;
}