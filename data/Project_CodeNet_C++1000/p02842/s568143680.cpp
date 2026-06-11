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
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000;
const double PI = acos(-1);
const int mod = 1000000007;


int main()
{
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        double price = (double)(i) * 1.08;
        if ((int)(price) == n) ans = i;
    }
    if (ans == 0) cout << ":(" << endl;
    else cout << ans << endl;
    return 0;
}
