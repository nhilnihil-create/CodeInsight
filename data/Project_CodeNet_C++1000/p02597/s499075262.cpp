#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans = 0,cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            cnt++;
    }
    for (int i = 0; i< cnt; i++)
    {
        if (s[i] == 'W')
            ans++;
    }
    cout << ans << endl;
}