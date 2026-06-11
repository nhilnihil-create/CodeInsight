#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long sum = 0, A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) continue;
        if (A[i] < A[i - 1]) {
            sum += (A[i - 1] - A[i]);
            A[i] = A[i - 1];
        }
    }
    cout << sum << endl;
}