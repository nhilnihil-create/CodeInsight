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


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> road(n, 0);
    for (int i = 0; i < n; i++)cin >> h[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        road[a] = max(road[a], h[b]);
        road[b] = max(road[b], h[a]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += h[i] > road[i];
    }
    cout << ans << endl;
}
