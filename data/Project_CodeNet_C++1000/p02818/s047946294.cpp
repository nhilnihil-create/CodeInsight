#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    long long A, B, K, afterA, afterK;
    cin >> A >> B >> K;
    afterA = max(A - K, (long long)0);
    afterK = max(K - A, (long long)0);
    B = max(B - afterK, (long long)0);
    cout << afterA << " " << B;
}
