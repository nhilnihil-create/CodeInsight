#include <iostream>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    bool pass = true, over = false;
    long long ans = 0;
    int alp[26][s.size()], now = -1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(i == s.size() - 1)
        {
            for(int j = 0; j < 26; j++)
            {
                alp[j][i] = -1;
            }
            alp[s[i] - 'a'][i] = i;
        }
        else
        {
            for(int j  =0; j < 26; j++)
            {
                alp[j][i] = alp[j][i + 1];
            }
            alp[s[i] - 'a'][i] = i;
        }
    }
    for(int i = 0, j = 0; i < t.size(); i++)
    {
        if(alp[t[i] - 'a'][j] == -1)
        {
            if(alp[t[i] - 'a'][0] == -1)
            {
                pass = false;
                break;
            }
            ans = ans + alp[t[i] - 'a'][0] + s.size() - now;
            j = alp[t[i] - 'a'][0] + 1;
            now = alp[t[i] - 'a'][0];
            if(j >= s.size())
            {
                j = 0;
            }
        }
        else
        {
            if(over)
            {
                ans = ans + alp[t[i] - 'a'][j] + s.size() - now;
                over = false;
            }
            else
            {
                ans = ans + alp[t[i] - 'a'][j] - now;
            }
            now = alp[t[i] - 'a'][j];
            j = alp[t[i] - 'a'][j] + 1;
            if(j >= s.size())
            {
                j = 0;
                over = true;
            }
        }
    }
    if(pass)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
