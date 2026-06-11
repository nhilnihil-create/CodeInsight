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
using vll = vector<vector<long long>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
int main() {
    ll a, b;
    cin >> a >> b;
    if (a * b % 2 == 0 && a != 1 && b != 1) {
        cout << a * b / 2 << endl;
    }
    else {
        if (a == 1 || b == 1) {
            cout << 1 << endl;
        }
        else {
            cout << a * b / 2 + 1 << endl;
        }
    }
}