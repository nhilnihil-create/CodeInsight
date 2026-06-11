#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    ll N;
    cin >> N;

    vector<ll> a(N);
   
    ll cnt = 0;

    rep(i, N) {
        cin >> a[i];
        if (a[i] == 0) {
            cnt++;
        }
    }

    sort(a.begin(), a.end());

    bool ans = false;

    if (cnt == N) {
        ans = true;
    }
    else if (N % 3 == 0) {
        if (cnt == N / 3) {
            ans = true;
            repl(i, N / 3, N) {
                if (a[i] != a[N / 3]) {
                    ans = false;
                    break;
                }
            }
        }
        else if (((a[0] ^ a[N / 3]) ^ a[2 * N / 3]) == 0) {
            ans = true;
            rep(i, 3) {
                repl(j, i * N / 3, (i + 1) * N / 3) {
                    if (a[j] != a[i * N / 3]) {
                        ans = false;
                        break;
                    }
                }
            }
        }
    }

    if(ans){
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}