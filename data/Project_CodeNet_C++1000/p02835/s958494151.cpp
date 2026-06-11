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
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
    return 0;
}