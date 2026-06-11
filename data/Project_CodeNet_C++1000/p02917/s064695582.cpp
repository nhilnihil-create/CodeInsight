#include <bits/stdc++.h>
using namespace std;

int main() { 
    int n;
    cin >> n;
    vector<int> B(n-1);
    for(int i = 0; i < n-1; i++) cin >> B[i];
    vector<int> A(n);
    A[0] = B[0];
    A[n-1] = B[n-2];
    for (int i = 1; i < n - 1; i++) {
      A[i] = min(B[i], B[i - 1]);
    }
    cout << accumulate(A.begin(), A.end() , 0) << endl;
    return 0;
}