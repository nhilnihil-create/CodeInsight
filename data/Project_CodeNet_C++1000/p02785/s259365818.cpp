#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using ii = vector<vector<long long>>;
int main() {
    ll n, k;
    cin >> n >> k;
    vl hp(n);
    for (int i = 0; i < n; i++) {
        cin >> hp[i];
    }
    bool a = true;
    sort(hp.begin(), hp.end());
    if (k >= n) {
        cout << 0 << endl;
        a = false;
    }
    ll count = 0;
    if (a) {
        for (int i = 0; i < n - k; i++) {
            count += hp[i];
        }
        cout << count << endl;
    }
}