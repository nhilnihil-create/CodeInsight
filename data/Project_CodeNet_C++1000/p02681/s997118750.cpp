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
{   string a,b; cin >> a >>b; b.pop_back();
    if (a==b) cout << "Yes";
    else cout << "No";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
