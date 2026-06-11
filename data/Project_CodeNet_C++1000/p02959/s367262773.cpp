#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1), B(N);
    for(int i=0; i<N+1; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];

    ll count = 0;

    for(int i=0; i<N; i++) {
        if(A[i] >= B[i]) {
            count += B[i];
            A[i] -= B[i];
        }
        else if(A[i] < B[i]) {
            count += A[i] + min(B[i] - A[i], A[i+1]);
            A[i+1] = max(A[i+1]-(B[i]-A[i]), 0);
        }
    }
    cout << count << endl;
}