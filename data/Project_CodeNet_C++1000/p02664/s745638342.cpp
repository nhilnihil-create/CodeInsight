#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for( int i =0; i < s.length(); i++ )
    {
        if(s[i] == '?') s.replace(i, 1, "D");
    }
    cout << s;

}