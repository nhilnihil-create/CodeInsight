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
    int k, a, b;
    cin >> k >> a >> b;
    for (int i = a; i <= b; i++) if (i % k == 0) {
        cout << "OK";
        return 0;
    }
    cout << "NG";
}
