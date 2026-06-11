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
    int p[123456] = {1, 1}, x;
    for (int i = 2; i <= 123444; i++) if (!p[i]) for (int j = i + i; j <= 123444; j += i) p[j] = 1;
    cin >> x;
    for (int i = x; ; i++) if (!p[i]) {
        cout << i;
        return 0;
    }
}
