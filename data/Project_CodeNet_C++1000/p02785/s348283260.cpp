#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long int sum = 0;
    for (int i=0; i<N-K; i++) sum += A[i];
    cout << sum << endl;
    return 0;
}
