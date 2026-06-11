#include <iostream> 
#include <cstdio> 
#include <cstdlib>  
#include <algorithm> 
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <tuple>
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    int yn = 1 << n;
    int ans = 1e9;
    for (int ms = 0; ms < yn; ms++) {
        vector<int> sum(m);
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if ((ms >> i) & 1) {
                cost += c[i];
                for (int j = 0; j < m; j++) {
                    sum[j] += a[i][j];
                }
            }
        }
        bool yes = true;
        for (int j = 0; j < m; j++) {
            if (sum[j] < x) yes = false;
        }
        if (yes) ans = min(ans, cost);
    }
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}
