#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

int main()
{
    map<string, int> c;
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for( int i = 0; i < n; i++ )
    {
        getline(cin, s);
        int l = 0;
        for( l = 0; l < s.length(); l++ )
        {
            if( s[l] < 'a' || s[l] > 'z') break;
        }
        c[s.substr(0, l)]++;

    }

    cout << c.size();

    return 0;    
}