#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int max_div = K-A[N-1] + A[0];
    for(int i=0; i<N-1; i++) {
        max_div = max(max_div, A[i+1]-A[i]);
    }
    cout << K - max_div << endl;
}