#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int output = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            tmp += pow(i - X[j], 2);
        }
        if (tmp < output) {
            output = tmp;
        }
    }

    cout << output << endl;

    return 0;
}
