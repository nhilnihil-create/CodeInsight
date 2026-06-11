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
{   si a; string b;
    cin >> a >> b;
    if(b.length()<=a) cout << b;
    else cout << b.substr(0,a)<<"...";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
