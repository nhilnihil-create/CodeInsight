#include<bits/stdc++.h>
using namespace std;

long long int A, B, K;

long long int max(long long int A, long long int B) { return A > B ? A : B; }

int main() {
    cin >> A >> B >> K;
    if (K >= A) cout << 0 << " " << max(0, B-(K-A));
    else cout << (long long) (A-K) << " " << B;
    return 0;
}
