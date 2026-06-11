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
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using ii = vector<vector<long long>>;
//#define int long long
int main() {
    ll n;
    cin >> n;
    vl a(n);
    bool x = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            x = false;
        }
    }
    if (x) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}