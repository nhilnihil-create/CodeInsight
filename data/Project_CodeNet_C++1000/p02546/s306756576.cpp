#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;
int main()
{
    int t;
    t=1;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.length();
        if(s[n-1]=='s')
        {
            cout << s << 'e' << 's';
        }
        else
        {
            cout << s << 's';
        }
    }
	return 0;
}