#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    bool ans = true;

    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        if (A.at(i) % 2 == 0) {
            if (A.at(i) % 3 && A.at(i) % 5) {
                ans = false;
            }
        }
    }

    cout << (ans ? "APPROVED" : "DENIED") << endl;
}