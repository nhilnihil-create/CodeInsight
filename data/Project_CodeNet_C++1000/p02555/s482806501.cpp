#include <iostream>
using namespace std;
const long long mod = 1000000007;

int main() {
    int S, A[2000];
    cin >> S;
    A[0] = A[1] = A[2] = 0;
    A[3] = 1;
    for (int i = 4; i <= S; i++) {
        A[i] = (A[i - 1] + A[i - 3]) % mod;
    }
    cout << A[S] << endl;
}