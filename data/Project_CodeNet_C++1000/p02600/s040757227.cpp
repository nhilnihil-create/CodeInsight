#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const long long N = 1e10 + 7;
const int maxn = 2e5 + 5;
const long long INF = 8e18;
typedef long long ll;
#define for0(i,n) for(int i = 0;i < n;i++)
#define for1(i,n) for(int i = 1;i <= n;i++)


int main()
{
    int x;
    cin >> x;
    if(x >= 400 && x <= 599 )
        cout << 8 << endl;
    else if(x >= 600 && x <= 799 )
        cout << 7 << endl;
    else if(x >= 800 && x <= 999 )
        cout << 6 << endl;
    else if(x >= 1000 && x <= 1199 )
        cout << 5 << endl;
    else if(x >= 1200 && x <= 1399 )
        cout << 4 << endl;
    else if(x >= 1400 && x <= 1599 )
        cout << 3 << endl;
    else if(x >= 1600 && x <= 1799 )
        cout << 2 << endl;
    else if(x >= 1800 && x <= 1999 )
        cout << 1 << endl;
    return 0;
}
