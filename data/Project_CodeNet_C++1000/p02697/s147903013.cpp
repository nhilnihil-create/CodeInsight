#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M;
    cin >> N >> M;
    if (N & 1) {
        for (int i = 1; i <= M; ++i)
            cout << i << " " << (N - i) << endl;
    } else {
        for (int i = 1; i <= M; ++i) {
            int tmp = N - i;
            if (N - 2 * i <= N / 2) --tmp;
            cout << i << " " << tmp << endl;
        }
    }
}
