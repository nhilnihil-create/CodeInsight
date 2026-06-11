#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int x, z = 0;
    cin >> x;
    z += (x / 500) * 1000;
    x %= 500;
    z += x / 5 * 5;
    cout << z;
}
