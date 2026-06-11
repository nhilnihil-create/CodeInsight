#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    string s,t;
    cin >> s >> t;
    int ans = t.size();
    for(int i = 0;i < s.size();i++)
    {
        int temp = t.size();
        for(int j = 0;j < t.size();j++)
        {
            if(!(i + j < s.size()))
            {
                cout << ans << "\n";
                return 0;
            }
            if(s[i + j] == t[j])
            {
                temp--;
            }
        }
        ans = min(ans,temp);
    }
    cout << ans << "\n";

    return 0;
}