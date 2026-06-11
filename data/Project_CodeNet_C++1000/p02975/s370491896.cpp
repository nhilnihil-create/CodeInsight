#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool allzero = true;
    bool zero = false;
    map<int ,int > mp;

    rep(i, n) {
        cin >> a[i];
        ++mp[a[i]];

        if (a[i]!=0) {
            allzero = false;
        }
        else {
            zero = true;
        }
    }

    bool ok = false;

    if (allzero) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n % 3 == 0) {
        int num = n / 3;

        if (zero) {
            int x = -1;
            rep(i, n) {
                if (a[i] != 0) {
                    x = a[i];
                }
            }
            if (mp[x] == num * 2 && mp[0] == num) {
                ok = true;
            }
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (a[i] != a[0]) {
                    int x = a[0], y = a[i], z = x ^ y;
                    if (mp.count(z)) {
                        if (mp[x] == num && mp[y] == num && mp[z] == num) {
                            ok = true;
                        }
                    }
                }
            }
        }
    }

    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}
