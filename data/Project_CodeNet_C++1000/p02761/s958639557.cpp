#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, m, a[5], b[5];
    cin >> n >> m;
    for (int in = 0; in < m; in++)
    {
        cin >> a[in] >> b[in];
    }

    for (int i = 0; i < 1000; i++)
    {
        string s = to_string(i);
        if (s.length() == n)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (s[a[j] - 1] != b[j] + '0')
                {
                    break;
                }
            }

            if (j == m)
            {
                cout << s << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    /*
    if (!m)
    {
        cout << -1 << endl;
        return 0;
    }

    string s = "";
    for (int asdf = 0; asdf < n; asdf++)
    {
        s += '?';
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        char y;
        cin >> x >> y;

        if (s[x - 1] == '?' || s[x - 1] == y)
        {
            s[x - 1] = y;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
        
    }

    if (n != 1 && s[0] == '0')
    {
        cout << -1 << endl;
        return 0;
    }

    if (s[0] ==  '?') s[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '?')
        {
            s[i] = '0';
        }
    }
 
    cout << s << endl;
    */
}