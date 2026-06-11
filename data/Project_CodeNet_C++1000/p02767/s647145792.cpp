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
    ll n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool aaaaa = true;
    if (n == 1) {
        cout << 0 << endl;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) {
                aaaaa = false;
            }
        }
        if (aaaaa) {
            cout << 0 << endl;
        }
        else {
            sort(a.begin(), a.end());
            vl count(abs(a[0] - a[n - 1]), 0);
            ll ans = 0;
            for (int j = 0; j < abs(a[0] - a[n - 1]); j++) {
                for (int i = 0; i < n; i++) {
                    ans += pow(abs(j - a[i]), 2);
                    if (i == n - 1) {
                        count[j] = ans;
                        ans = 0;
                    }
                }
            }
            sort(count.begin(), count.end());
            cout << count[0] << endl;
        }
    }
}