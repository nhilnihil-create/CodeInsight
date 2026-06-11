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
    int a, b, x;
    cin >> a >> b >> x;
    if (2 * x < a * a * b) {
        printf("%.6f", atan((ll)a * b * (double)b / 2 / x) / PI * 180);
    }
    else {
        printf("%.6f", atan((double)(2 * ((ll)a * a * b - x)) / a / a / a) / PI * 180);
    }
    return 0;
}