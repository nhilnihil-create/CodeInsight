#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool ok = true;
    if (N % 2 != 0) {
        ok = false;
    }
    else {
        for (int i = 0; i < N / 2; ++i) {
            if (S[i] != S[N / 2 + i]) {
                ok = false;
                break;
            }
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
