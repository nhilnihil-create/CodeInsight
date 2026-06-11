#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        B.at(i) = A.at(i);
    }
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        if (B.at(0) != A.at(i)) cout << B.at(0) << endl;
        else cout << B.at(1) << endl;
    }
}