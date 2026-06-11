#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<pair<int, int>> X(N, make_pair(0, 0));
    for (int i = 0; i < N; ++i) {
        cin >> X[i].first >> X[i].second;
    }

    sort(X.begin(), X.end());
    double sum = 0;
    do {
        for (int i = 1; i < N; ++i) {
            int x0 = X[i - 1].first;
            int y0 = X[i - 1].second;
            int x = X[i].first;
            int y = X[i].second;
            sum += sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
        }
    } while (next_permutation(X.begin(), X.end()));

    for (int i = 1; i <= N; ++i) {
        sum /= (double)i;
    }
    cout << sum << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
