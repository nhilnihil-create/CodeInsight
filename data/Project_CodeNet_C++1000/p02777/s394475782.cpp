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
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (u == s) {
        cout << a - 1 << " " << b << endl;
    }
    else {
        cout << a << " " << b - 1 << endl;
    }
    return 0;
}