#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> X(N, 0), L(N, 0);
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> L[i];
        P[i].second = (X[i] - L[i]), P[i].first = (X[i] + L[i]);
    }
    sort(P.begin(), P.end());
    long long int cnt = 0, now = -10e9;
    for (int i = 0; i < N; i++) {
        if (now <= P[i].second) {
            cnt++;
            now = P[i].first;
        }
    }
    cout << cnt << endl;
}
