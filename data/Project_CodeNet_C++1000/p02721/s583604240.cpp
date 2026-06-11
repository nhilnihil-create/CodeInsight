#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N, K, C;
string S;
int a[201010], b[201010];

int main()
{
    cin >> N >> K >> C;
    cin >> S;

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (cnt == K) {
            break;
        }

        if (S[i] == 'o') {
            a[cnt] = i;
            cnt++;
            i += C;
        }
    }

    cnt = K - 1;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (cnt < 0) {
            break;
        }

        if (S[i] == 'o') {
            b[cnt] = i;
            cnt--;
            i -= C;
        }
    }

    for (int i = 0; i < K; i++) {
        if (a[i] == b[i]) {
            cout << a[i] + 1 << endl;
        }
    }
}
