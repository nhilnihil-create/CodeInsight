#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    bool check=false;
    string s,t;
    cin >> s;
    cin >> t;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            check=true;
        }
    }
    if(check)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    
    return 0;
}
