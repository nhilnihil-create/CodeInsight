#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int ans = 1001;

    for (int i = 0; i < s.size() - t.size() + 1; ++i)
    {
        int count = 0;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                count++;
            }
        }
        ans = min(ans,count);
    }
    cout << ans << endl;
}   