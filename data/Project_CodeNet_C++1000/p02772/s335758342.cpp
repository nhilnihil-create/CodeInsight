//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            if (A[i] % 3 != 0 && A[i] % 5 != 0) {
                cout << "DENIED" << endl;
                return;
            }
        } 
    }

    cout << "APPROVED" << endl;
}


int main() {
    solve();
    return 0;
}