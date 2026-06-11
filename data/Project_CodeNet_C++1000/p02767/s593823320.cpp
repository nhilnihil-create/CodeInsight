#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
        sum += X.at(i);
    }
    sum = round(sum / (double)N);
    int ans = 0;
    for (auto i : X) {
        ans += (i - sum) * (i - sum);
    }
    cout << ans << endl;
}
