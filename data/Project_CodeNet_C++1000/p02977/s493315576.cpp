#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    if(__builtin_popcount(n) == 1) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    cout << 1 << " " << 2 + n << "\n";
    cout << 2 + n << " " << 3 + n << "\n";
    cout << 3 + n << " " << 1 + n << "\n";
    cout << 1 + n << " " << 2 << "\n";
    cout << 2 << " " << 3 << "\n";

    for(i = 4; i < n; i += 2) {
        cout << i << " " << i + 1 << "\n";
        cout << i << " " << n + 1 << "\n";
        cout << i + 1 + n << " " << i + n << "\n";
        cout << i + 1 + n << " " << n + 1 << "\n";
    }

    if(n % 2 == 0) {
        for(i = 4; i < n; i++) {
            int a = i, b = (n ^ i ^ 1);
            if(b > 1 && b < n && b != a) {
                if(a & 1) {
                    cout << n << " " << a + n << "\n";
                }
                else {
                    cout << n << " " << a << "\n";
                }
                if(b & 1) {
                    cout << 2 * n << " " << b + n << "\n";
                }
                else {
                    cout << 2 * n << " " << b << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}
