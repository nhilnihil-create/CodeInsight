#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef short int si;
using namespace std;

void solve()
{   si a; cin >>a;
    a%=10; 
    switch(a)
    {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        cout << "hon"; break;
    case 0:
    case 1:
    case 6:
    case 8:
        cout << "pon"; break;
    case 3:
        cout << "bon"; break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
