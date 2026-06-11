#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    int n;
    string s;
    cin >> n >> s;
    char cnt = s[0];
    int ans = 1;
    for (char c : s)
    {
        if (c != cnt)
        {
            cnt = c;
            ans++;
        }
    }
    cout << ans << endl;
}