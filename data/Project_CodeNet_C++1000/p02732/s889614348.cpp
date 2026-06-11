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

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<ll> cnt(N + 1);
    Rep(i, N) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    ll ans = 0;
    Rep(i, cnt.size()) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    Rep(i, N) {
        cout << ans - cnt[A[i]] + 1 << endl;
    }
    return 0;
}