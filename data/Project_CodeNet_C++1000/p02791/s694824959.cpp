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

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    int ans = 0;
    int MIN = 1e9 + 7;
    for (int i = 0; i < N; i++) {
        MIN = min(MIN, P[i]);
        if (P[i] <= MIN) ans++;
    }
    cout << ans << endl;
}
