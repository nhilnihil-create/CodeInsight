#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    int x; cin >> x;
    if (x < 600) cout << 8 << endl;
    else if (x < 800) cout << 7 << endl;
    else if (x < 1000) cout << 6 << endl;
    else if (x < 1200) cout << 5 << endl;
    else if (x < 1400) cout << 4 << endl;
    else if (x < 1600) cout << 3 << endl;
    else if (x < 1800) cout << 2 << endl;
    else if (x < 2000) cout << 1 << endl;
    return 0;
}