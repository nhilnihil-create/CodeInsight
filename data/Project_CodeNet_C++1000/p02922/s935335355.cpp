#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int a, b; cin >> a >> b;
    int t = 0;
    int num = 1;
    while( num < b )
    {
        num += a - 1;
        t++;
    }
    cout << t << endl;
    return 0;    
}