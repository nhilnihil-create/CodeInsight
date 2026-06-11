#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> P(N, 0);
    for(int i = 0; i < Q; i++) {
        int A;
        cin >> A;
        A--;
        P[A]++;
    }
    for(int p : P) {
        if(K - Q + p > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}