#include <iostream>
using namespace std;

int N, *X;

void input() {
    cin >> N;
    X = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i]; 
    }
}

void solve() {
    int ans;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < N; j++) {
            sum += (X[j] - i) * (X[j] - i);
        }
        if (i == 1) {
            ans = sum;
        } else {
            if (sum < ans) {
                ans = sum;
            }
        }
        sum = 0;
    }
    cout  << ans << endl;
}

void free() {
    delete[] X;
}

int main() {
    input();
    solve();
    free();
    return 0;
}