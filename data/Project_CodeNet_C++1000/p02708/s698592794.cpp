#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int main() {
    long long N, K;
    cin >> N >> K;
    long long M = N+1, L = K-1;
    long long res = M*(M*M+5)/6 + L*(L*L*2+L*3-5-M*(L+1)*3)/6;
    cout << res%MOD << endl;
}