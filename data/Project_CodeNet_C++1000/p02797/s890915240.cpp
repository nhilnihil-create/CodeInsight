#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    vector<int> A(N, S + 1);
    for(int i = 0; i < K; i++) {
        A.at(i) = S;
    }
    for(int i = K; i < N; i++) {
        if(S == 1000000000) {
            A.at(i) = 1000000000 - 1;
        }
    }

    for(int i = 0; i < N - 1; i++) {
        cout << A.at(i) << " ";
    }

    cout << A.at(N - 1) << endl;
}