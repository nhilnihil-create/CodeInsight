#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    if(s.size() % 2 == 1)
    {
        cout << "No\n";
        return 0;
    }
    for(int i = 0;i < s.size();i++)
    {
        if(!(i % 2 == 0 && s[i] == 'h' || i % 2 == 1 && s[i] == 'i'))
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
}