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
#define int long long
#define double long long
using namespace std;
signed main() {
    int N, X;
    cin >> N >> X;
    int A = 0;
    int i;

    vector<int>L(N);

    for (i = 0; i < N; i++) {
        cin >> L.at(i);
        A += L.at(i);
        if (A > X) {
            break;
        }
        
    }
    cout << i + 1 << endl;
}
