#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int X;
    cin >> X;
    for (ll x = -1000; x <= 1000; x++) {
        for (ll y = -1000; y <= 1000; y++) {
            ll a = x * x * x * x * x, b = y * y * y * y * y;
            if (a - b == X) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }
    return 0;
}