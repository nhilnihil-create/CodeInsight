#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int main()
{
    string s,t;
    cin >> s>>t;
    int a=0,i;
    rep0(i,s.size()){
        if(s[i]!=t[i])a++;
    }
    cout << a << endl;
    return 0;
}