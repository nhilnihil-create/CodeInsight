#include <bits/stdc++.h>
using namespace std;

int main(){
    long long S;
    cin >> S;
    long long X1, Y1, X2, Y2;
    X1 = Y2 = sqrt(S + 0.5);
    if (X1 * Y2 < S) ++X1;
    if (X1 * Y2 < S) ++Y2;
    Y1 = X1 * Y2 - S; X2 = 1;
    cout << "0 0 " << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << endl;
    return 0;
}