#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N, K - Q);
    for(int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        A.at(t - 1)++;
    }
    for(int i = 0; i < N; i++) {
        if(A.at(i) > 0) {
        cout << "Yes" << endl;
        } else {
        cout << "No" << endl;
        }
    }



    return 0;
}