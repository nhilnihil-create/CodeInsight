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
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    int minA = 1e6, minB = 1e6;
    for (int i = 0; i < A; i++) {
        cin >> a[i];
        minA = min(minA, a[i]);
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i];
        minB = min(minB, b[i]);
    }
    int ans = minA + minB;
    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        ans = min(ans, a[x - 1] + b[y - 1] - c);
    }
    cout << ans << endl;
}
