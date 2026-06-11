//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int tt;
    tt = 1;
    while (tt--)
    {
        string s, t; cin >> s; cin >> t;
        int i, j, count = 0;
        vector<int> v;
        //cout << s.length() - t.length() << " " << endl;
        for (i = 0; i <= (s.length() - t.length()); i++)
        {
            count = 0;
            for (j = i; j < i + t.length(); j++)
            {
                if (s[j] != t[j - i])
                {
                    count++;
                }
            }
            //cout << count << " " << endl;
            v.push_back(count);
        }
        sort(v.begin(), v.end());
        cout << v[0] << " " << endl;
    }
    return 0;
}