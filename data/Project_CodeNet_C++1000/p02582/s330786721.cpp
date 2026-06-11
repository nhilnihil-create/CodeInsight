#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_in_out;
    string s;
    cin >> s;
    int c = 0;
    if(s[0] == 'R')
    {
        c++;
        if(s[1] == 'R')
        {
            c++;
            if(s[2] == 'R')
            {
                c++;
            }
        }
    }
    else if(s[1] == 'R')
    {
        c++;
        if(s[2] == 'R')
        {
            c++;
        }
    }
    else if(s[2] == 'R')
    {
        c++;
    }
    cout << c;
}
