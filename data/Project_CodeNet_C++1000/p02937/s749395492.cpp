#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    vector<vector<long long>> count(26);
    for (long long i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a'].push_back(i);
    }
    long long mem = -1;
    long long ans = 0;
    for (long long i = 0; i < t.size(); i++)
    {
        if (count[t[i] - 'a'].size() == 0)
        {
            cout << -1 << endl;
            exit(0);
        }
        else
        {
            long long answer;
            long long min = -1;
            long long max = count[t[i] - 'a'].size();
            while (1)
            {
                if (max - min == 1)
                {
                    answer = max;
                    break;
                }
                else
                {
                    if (count[t[i] - 'a'][(max + min)/2] > mem)
                    {
                        max = (max + min)/2;
                    }
                    else
                    {
                        min = (max + min)/2;
                    }
                }
            }
            if (answer == count[t[i] - 'a'].size())
            {
                ans += s.size() - mem + count[t[i] - 'a'][0];
                mem = count[t[i] - 'a'][0];
            }
            else
            {
                ans += count[t[i] - 'a'][answer] - mem;
                mem = count[t[i] - 'a'][answer];
            }
            
        }
    }
    cout << ans << endl;
}