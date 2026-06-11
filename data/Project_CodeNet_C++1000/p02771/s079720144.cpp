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
    int a[3] = {};
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == a[1] && a[1] != a[2]) cout << "Yes";
    else if (a[0] != a[1] && a[1] == a[2]) cout << "Yes";
    else cout << "No";
}
