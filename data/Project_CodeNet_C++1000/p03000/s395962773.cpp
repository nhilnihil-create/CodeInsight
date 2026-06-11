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
    int n, x;
    cin >> n >> x;
    int res = 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c += t;
        if (c <= x) res++;
    }
    cout << res << endl;
}
