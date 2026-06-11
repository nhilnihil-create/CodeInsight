#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    int N, M, sum = 0, cnt = 0;
    cin >> N >> M;
    double diff = 1 / (double)(4 * M);
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    for (int i = 0; i < N; i++) sum += A.at(i);

    vector<bool> ok(N, true);

    for (int i = 0; i < N; i++) {
        if ((double)A[i] < (double)sum * diff) ok[i] = false;
    }

    for (int i = 0; i < N; i++) {
        if (ok.at(i)) cnt++;
    }

    if (cnt >= M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}