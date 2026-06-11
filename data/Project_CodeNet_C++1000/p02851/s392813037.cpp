#include <bits/stdc++.h>
 
typedef long long LL;
typedef unsigned long long LONG;
const int N = 1e5 + 5;
using namespace std;
typedef pair<int, int> PII;
#define ft fisrt
#define sd second
#define eb emplace_back
 
template<class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (static_cast<void>(c = getchar()), c == EOF) return 0;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (static_cast<void>(c = getchar()), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
 
LL a[N * 5], k, n;
LL ans = 0, sum[N * 5] = {0};
map<unsigned int, LL> num;
 
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i <= n; ++i) {
        if (i - k >= 0) {
            num[(sum[i - k] - (i - k)) % k]--;
        }
        if (num.count((sum[i] - i) % k)) {
            ans += num[(sum[i] - i) % k];
        }
        num[(sum[i] - i) % k]++;
    }
    cout << ans;
    return 0;
}