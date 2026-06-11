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
//#define int long long  ←保留
#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for (int i = 0; i < n; i++)
#define _GLIBCXX_DEBUG
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279; //円周率
/*---------------------便利な関数--------------------------------------*/
int fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}

int gcd(int a, int b) {        //最大公約数
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {      //最小公倍数
    return a * b / gcd(a, b);
}

int keta(int n) {        //桁数を求める
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int ketasum(int n) {    //各桁の和
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/*-------------ここまで---------------------------------------------*/

//C++(GCC9.2.1)

/*signed*/int main() {
    int n, m; cin >> n >> m;
    vector<int> broken(n + 2, false);
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        broken[a] = true;
    }
    vector<long long> dp(n + 2, 0);
    dp[0] = 1;
    if (!broken[1]) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!broken[i]) {
            dp[i] += dp[i - 1] + dp[i - 2];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}