#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n + 1; i++) {
        cin >> v[i];
    }
    long long int res = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (h >= v[i]) {
            res += v[i];
            h -= v[i];
        } else {
            res += h;
            h = 0;
        }
        if (h >= v[i + 1]) {
            res += v[i + 1];
            v[i + 1] = 0;
        } else {
            res += h;
            v[i + 1] -= h;
        }
    }
    cout << res << endl;
}
