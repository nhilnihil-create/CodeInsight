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

// aとbの最大公約数を求める関数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int k;
    cin >> k;

    int ans = 0;
    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= k; b++) {
            for (int c = 1; c <= k; c++) {
                int tmp = gcd(a, b);
                ans += gcd(tmp, c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}