#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    int n,k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for(int i = 1;i < s.size();i++)
    {
        if(s[i - 1] == s[i])
        {
            ans++;
        }
    }
    cout << min(ans + 2 * k,n - 1) << "\n";

    return 0;
}