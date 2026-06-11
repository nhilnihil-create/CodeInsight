#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    int q; cin >> q;
    int inv = 0;
    int t, f;
    string c;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1) inv = 1 - inv;
        else
        {
            cin >> f >> c;
            if ((f == 1 && inv == 0) || (f == 2 && inv == 1)) 
                s.insert(0, c);
            else
                s.append(c); 
        }
    }
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (inv == 0) 
            cout << s[i];
        else
            cout << s[l - i - 1]; 
    }
    cout << endl;
}