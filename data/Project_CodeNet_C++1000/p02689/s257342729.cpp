#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;
 
int main(void) {
    Int n, m;
    cin >> n >> m;
    Int a, b;
    vector<Int> h(n);
    vector<Int> max_h(n);
    vector<bool> check(n, true);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
        max_h[i] = h[i];
    }
    vector<vector<Int> > table(n);
    for (Int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        if (h[a] == h[b]) {
            check[a] = false;
            check[b] = false;
        } else if (h[a] < h[b]) {
            check[a] = false;
            max_h[a] = max_h[b];
        } else {
            check[b] = false;
            max_h[b] = max_h[a];
        }
    }
    Int true_cnt = 0;
    for (Int i = 0; i < n; ++i) {
        if (check[i]) {
            true_cnt++;
        }
    }
    cout << true_cnt << endl;
    return 0;
}
