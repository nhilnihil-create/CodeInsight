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
{   int a,b,c,k; cin >> a >> b >> c >> k;
    if(k-a<=0) cout << k;
    else
    {
        if(k-a-b<=0) cout << a;
        else cout << a-(k-a-b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
