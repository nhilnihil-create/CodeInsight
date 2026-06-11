#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    if(s[0]=='R')
    {
        if(s[1]=='R')
        {
            if(s[2]=='R')
            {
                cout << "3\n";
            }
            else cout << "2\n";
        }
        else cout << "1\n";
    }
    else if(s[1]=='R')
    {
        if(s[2]=='R')
            cout << "2\n";
        else cout << "1\n";
    }
    else if(s[2]=='R')
    {
        cout << "1\n";
    }
    else cout << "0\n";
    
}