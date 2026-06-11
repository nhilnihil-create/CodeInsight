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
	int K; cin >> K;
    ll ans = 0;
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
            for (int k = 1; k <= K; k++)
                ans += GCD(GCD(i, j), k);
    cout << ans << endl;
}
