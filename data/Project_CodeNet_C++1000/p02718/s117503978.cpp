#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    double sum = 0.0;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    sum /= (4 * M);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A.at(i) >= sum) {
            cnt++;
        }
    }
    cout << (cnt >= M ? "Yes" : "No") << endl;
}
