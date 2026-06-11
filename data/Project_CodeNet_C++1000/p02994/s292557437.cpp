#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, L, memo;
    cin >> N >> L;
    int mini = 1000, sum = 0;
    rep(i, N) {
        if(abs(mini) > abs(L + i)) {
            mini = L + i;
        }
        sum = sum + L + i;
    }
    cout << sum - mini << endl;
    return 0;
}
