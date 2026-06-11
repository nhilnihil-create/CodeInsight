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
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < 1 || a>9 || b < 1 || b>9) {
        cout << -1 << endl;
    }
    else {
        cout << a * b << endl;
    }
    return 0;
}