#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> P(N, 0), Q(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
    }

    vector<int> X;
    for (int i = 1; i <= N; ++i) {
        X.push_back(i);
    }

    int counter = 0;
    int np = -1;
    int nq = -1;
    do {
        int diffp = 0;
        int diffq = 0;
        for (int i = 0; i < N; ++i) {
            diffp += abs(X[i] - P[i]);
            diffq += abs(X[i] - Q[i]);
        }
        if (diffp == 0) {
            np = counter;
        }
        if (diffq == 0) {
            nq = counter;
        }
        ++counter;
        if (np >= 0 && nq >= 0) {
            break;
        }
    } while (next_permutation(X.begin(), X.end()));

    cout << abs(np - nq) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
