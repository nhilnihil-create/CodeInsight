#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

ll atack(ll N, ll ans, int cnt) {
    if (N == 0) return ans;
    else return atack(N / 2, ans += (ll)pow(2, cnt), cnt + 1);
}

int main() {
    ll H;
    cin >> H;
    cout << atack(H, 0, 0) << endl;
    return 0;
}