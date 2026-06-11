#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int mod;
long long int mypow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long int res = mypow(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 1) res = res * a % mod;
    return res;
}

int main() { 
    int n;
    cin >> n >> mod;
    string s;
    cin >> s;
    long long int res = 0;
    long long int last = 0;
    if (mod == 2 || mod == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % mod == 0) {
                res += i + 1;
            }
        }
        cout << res << endl;
        return 0;
    }
    unordered_map<long long int, long long int> um;
    um[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        long long int next = last + mypow(10, n - 1 - i) * (s[i] - '0') % mod;
        next %= mod;
        res += um[next];
        um[next]++;
        last = next;
    }

    cout << res << endl;
}


