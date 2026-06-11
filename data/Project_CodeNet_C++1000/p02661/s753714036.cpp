#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(N % 2 == 1) {
        cout << B[(N-1)/2] - A[(N-1)/2] + 1 << endl;
    }
    else {
        cout << (B[N/2] + B[N/2-1]) - (A[N/2] + A[N/2-1]) + 1 << endl;
    }

    return 0;
}