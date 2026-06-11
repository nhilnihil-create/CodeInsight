#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i;
    cin >> s;

    for( i=0; i<s.size(); i++)
    {
        if(s[i]=='7')
        {

            cout<<"Yes";
            return 0;
        }

    }
    cout<<"No";
}
