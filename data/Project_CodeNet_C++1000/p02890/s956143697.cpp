#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 3 * 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    vector<int> B(N + 1, 0);
    rep(i, N) {
        B[ A[i] ]++;
    }

    vector<int> C(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        C[ B[i] ]++;
    }

    vector<int> sumC(N + 1), sumCi(N + 1);
    sumC[0] = sumCi[0] = 0;
    for (int i = 1; i <= N; ++i) {
        sumC[i] = sumC[i - 1] + C[i];
        sumCi[i] = sumCi[i - 1] + C[i] * i;
    }

    for (int i = 1; i <= N; ++i) {
        int l = 0, r = N + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int res = (sumC[N] - sumC[mid]) * mid + sumCi[mid];
            res /= mid;
            if (i <= res) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
}