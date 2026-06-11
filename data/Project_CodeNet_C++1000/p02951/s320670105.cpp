#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = c - (a - b);
    if (ans > 0) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}