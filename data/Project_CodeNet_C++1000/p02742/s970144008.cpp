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
//#define int long long    ←保留
#define rep(i, n) for (int i = 0; i < n; i++)
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279; //円周率
//C++(GCC9.2.1)

/*signed*/int main() {
    //宣言
    long long H;
    long long W;
    cin >> H >> W;
    long long sum = H * W;
    if ((H == 1) || (W == 1)) sum = 1;
    else if (sum % 2 == 0) sum = sum / 2;
    else sum = sum / 2 + 1;
    cout << sum << endl;
    return 0;
}