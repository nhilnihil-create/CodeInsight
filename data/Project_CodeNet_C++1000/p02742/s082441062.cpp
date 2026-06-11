#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    ll h, w;
    cin >> h >> w;
    
    if (h == 1 || w == 1) cout << 1 << endl;
    else cout << (h * w + 1) / 2 << endl;
    return 0;
}