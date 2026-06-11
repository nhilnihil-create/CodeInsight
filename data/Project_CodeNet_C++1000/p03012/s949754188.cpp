#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;
    int W[N];
    int sum = 0;

    rep(i, N) {
        cin >> W[i];
        sum += W[i];
    }

    int mini = sum;
    int prefix_sum = 0;

    rep(i, N) {
        prefix_sum += W[i];
        mini = min(mini, abs(prefix_sum - (sum - prefix_sum)));
    }

    cout << mini << endl;

    return 0;
}