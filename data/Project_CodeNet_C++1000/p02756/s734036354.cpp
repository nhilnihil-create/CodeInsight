#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    int t, f;
    string c;
    int count = 0 ;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            count ++ ;
        }
        else
        {
            cin >> f >> c ;
            if(f==1)
            {
                if(count%2)
                {
                    reverse(s.begin(),s.end());
                }
                s = c+s ;
            }
            else
            {
                if(count%2)
                {
                    reverse(s.begin(),s.end());
                }
                s += c ;
            }
            count = 0 ;
        }
    }
    if(count%2)
    {
        reverse(s.begin(),s.end());
    }
    cout << s << endl  ;
}