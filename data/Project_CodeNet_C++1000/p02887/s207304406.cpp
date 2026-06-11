#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    cin >> n; 
        cin >> s;
    auto curr = s[0];
    int ans = 1;
    for (auto c : s)
    {
        if (c != curr)
        {
            curr = c;
            ans++;
        }
    }
    cout << ans << endl;

}
