#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll A;
    string B;
    cin >> A >> B;

    int C[3];
    C[0] = B[0] - '0';
    C[1] = B[2] - '0';
    C[2] = B[3] - '0';

    ll D[3];
    D[0] = A * C[0] * 100;
    D[1] = A * C[1] * 10;
    D[2] = A * C[2];

    ll res = (D[0] + D[1] + D[2]) / 100;
    cout << res;
    return 0;
}