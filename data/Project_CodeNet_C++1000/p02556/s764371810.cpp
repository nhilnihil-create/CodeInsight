#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdint.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>

#include <algorithm>
#include <functional>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>

#define sqr(x) (x) * (x)

typedef unsigned int u32;
typedef int i32;
typedef unsigned long long int u64;
typedef long long int i64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

using namespace std;
using namespace std::chrono;

//const i64 mod = 1'000'000'000ll + 7;
const i64 smod = 998244353ll;

//const i64 inf = mod;

const long double eps = 1e-8;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout.setf(ios::fixed); cerr.precision(15); cerr.setf(ios::fixed);

    i64 n;
    cin >> n;

    pair<i64, i64> m[2];

    for (i64 i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;

        i64 t[2] = { x + y, x - y };

        for (i64 j = 0; j < 2; j++) {
            if (!i || m[j].first < t[j]) {
                m[j].first = t[j];
            }
            if (!i || m[j].second > t[j]) {
                m[j].second = t[j];
            }
        }
    }

    i64 R = max(abs(m[0].first - m[0].second), abs(m[1].first - m[1].second));
    cout << R << endl;


    return 0;
}