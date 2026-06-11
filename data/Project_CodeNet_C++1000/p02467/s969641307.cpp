#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    cout << N << ": ";
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            cout << i;
            N /= i;
            if (N != 1) cout << " ";
        }
    }
    if (N != 1) cout << N;
    cout << endl;
    return 0;
}