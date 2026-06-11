
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 

const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;

    vector<LL> a(N);
    LL s = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        s ^= a[i];
    }

    for (int i = 0; i < N; ++i) {
        a[i] &= ~s;
    }

    vector<int> top(N);
    int r = 0;
    for (int i = 60; 0 <= i; --i) {
        int j = r;
        for (; j < N; ++j) {
            if ((a[j]>>i)&1) {
                swap(a[r], a[j]);
                break;
            }
        }
        if (j == N) continue;
        top[r] = i;
        for (int k = 0; k < N; ++k) {
            if (k != r && ((a[k]>>i) & 1)) {
                a[k] ^= a[r];
            }
        }
        ++r;
    }

    LL x = 0;
    for (int i = 60; 0 <= i; --i) {
        LL nx = x | (1LL << i);
        LL b = nx;
        for (int j = 0; j < r; ++j) {
            if (b>>top[j]&1) {
                b ^= a[j];
            }
            if ((b&nx) == 0) {
                x = nx;
            }
        }
    }

    LL ans = s + x * 2;

    cout << ans << endl;

    return 0;
}
