#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
typedef long long ll;
using namespace std;


    int main()
{
    SRK;
    string s;
    cin >> s;
    if (s[0] == 'R')
    {
        if (s[1] == 'R')
        {
            if (s[2] == 'R')
            {
                cout << "3\n";
            }
            else
            {
                cout << "2\n";
            }
        }
        else
        {
            cout << "1\n";
        }
    }
    else if (s[1] == 'R')
    {
        if (s[2] == 'R')
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    else if (s[2] == 'R')
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

}

