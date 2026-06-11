#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vector<int> B(N);
    B = A;
    sort(B.begin(), B.end());
    int max1 = B[N-1];
    int max2 = B[N-2];

    for(int i=0; i<N; i++) {
        if(A[i] == max1) cout << max2 << endl;
        else cout << max1 << endl;
    }
}