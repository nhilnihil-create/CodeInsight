#include <bits/stdc++.h>
using namespace std;
long long T1, T2, A1, A2, B1, B2;
int main() {
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    long long SA = A1*T1 + A2*T2;
    long long SB = B1*T1 + B2*T2;
    if(SA == SB) cout << "infinity";
    else if((SA > SB && A1 > B1) || (SA < SB && A1 < B1)) cout << 0;
    else {
        long long ds = abs(SA - SB);
        long long rd = abs(A1 - B1) * T1;
        long long ans = (rd / ds) * 2;
        if(rd % ds) ans++;
        cout << ans;
    }
}