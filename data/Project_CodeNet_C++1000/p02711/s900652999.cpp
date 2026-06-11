#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;

    bool is_ok = false;
    rep(i, 3) {
        if (n % 10 == 7) is_ok = true;
        n /= 10;
    }
    if (is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}