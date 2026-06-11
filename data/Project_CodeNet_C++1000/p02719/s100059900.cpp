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
typedef long double ld;
using namespace std;
void solve()
{
    ull n,k; cin >> n >> k;
    n%=k; cout << min(n,k-n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
