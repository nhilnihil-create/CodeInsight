#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<char, int> mp;
    mp['r'] = 0;
    mp['p'] = 1;
    mp['s'] = 2;
    int n, k, val[3], ans = 0;
    string s;
    cin >> n >> k >> val[2] >> val[1] >> val[0] >> s;

    vector<int> prev(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (i - k >= 0 && s[i] == s[i - k] && !prev[i - k]) continue;
        ans += val[mp[s[i]]];
        prev[i] = 0;
    }

    cout << ans << "\n";
}