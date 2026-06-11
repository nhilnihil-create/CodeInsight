#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, ave, max, ans;
    cin >> N;
    vector<int>A(N);
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
        sum ^= A[i];
    }
    for (long long i = 0; i < N; i++) {
        cout << (sum ^ A[i]);
        if (i < N-1) {
            cout << ' ';
        }
    }
    cout << endl;
 
    
}

