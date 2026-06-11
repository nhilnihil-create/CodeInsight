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
    int n,k;
    cin >> n >> k;
    vector<int> H(n);
    for (int i = 0; i < n; i++) cin >> H[i];
    sort(H.begin(), H.end());
    ll ans = 0;
    if(n-k>0)
    for (int i = n - k - 1; i >= 0; i--) ans += H[i];
    cout << ans << endl;
}
