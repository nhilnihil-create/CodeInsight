#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    
    vector<int> A;
    for (int i = 0; i < K; i++) A.push_back(S);

    int x = 1;
    if (S < 1000000000) x += S;

    for (int i = 0; i < N - K; i++) A.push_back(x);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}