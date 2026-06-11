#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;
    string s;
    cin >> s;
    if(s[0] == 'S' && s[1] == 'S' && s[2] == 'S' )
    {
        cout << "0\n";
    }
    else if(s[0] == 'R' && s[1] == 'R' && s[2] == 'R' )
    {
        cout << "3\n";
    }
    else if((s[0] == 'R' && s[1] == 'R' && s[2] == 'S' ) || (s[0] == 'S' && s[1] == 'R' && s[2] == 'R' ))
    {
        cout << "2\n";
    }
    else if((s[0] == 'R' && s[1] == 'S' && s[2] == 'S' ) || (s[0] == 'R' && s[1] == 'S' && s[2] == 'R' ) || (s[0] == 'S' && s[1] == 'S' && s[2] == 'R' ) || (s[0] == 'S' && s[1] == 'R' && s[2] == 'S' ))
    {
        cout << "1\n";
    }



}
