#include <iostream>
using namespace std;

int main() {
    int N, K, S; cin >> N >> K >> S;
    int A[N];
    for (int i = 0; i < N; i++) {
        if (i < K) A[i] = S;
        else {
            if (S < 1000000000) A[i] = S + 1;
            else A[i] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}