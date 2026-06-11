#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long ll;
#define pi 3.14159265358979323846264338327950L



// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    long double rad = abs((long double)m * 6 - ((long double)h * 30 + ((long double)m * 6) / 12))/180*pi;
    long double ans = sqrt((long double)(a * a + b * b) - (long double)(2 * a * b * cos(rad)));
    cout << fixed << setprecision(10) << ans << endl;
}
