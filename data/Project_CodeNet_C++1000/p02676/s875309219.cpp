#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
    ll k;
    string s;
    cin >> k;
    cin >> s;
    if(s.length() <= k)
    {
        cout << s << endl;
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            cout << s[i];
        }
        cout << "..." << endl;
    }
    
    return 0;
}
