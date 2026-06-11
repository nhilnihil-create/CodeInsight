#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main()
{
    int testcase;

    string s;
    cin >> s ;
    int r=0;
    if(s[0]=='R')
        r++;
    for(int i=1; i<3; i++)
    {
        if(s[i]=='R')
        {
            if(s[i-1]=='R')
                r++;
            else
                r=1;
        }
    }
    cout << r ;
    return 0;
}