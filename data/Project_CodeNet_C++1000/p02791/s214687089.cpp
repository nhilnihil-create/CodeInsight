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
    int n, a[200005] = {}, b = mod, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < b) b = a[i], z++;
    }
    cout << z;
}
