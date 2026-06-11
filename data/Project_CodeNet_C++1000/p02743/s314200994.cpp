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
    ll a, b, c;
    cin >> a >> b >> c;
    
    if (c - a - b < 0) {
        cout << "No" << endl;
        return 0;
    }
    
    cout << (4 * a * b < (c - a - b) * (c - a - b) ? "Yes" : "No") << endl;
    return 0;
}