#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t A;
    double B;
    cin >> A >> B;
    B *= 100;
    __int128 BB = (int64_t)round(B);
    A *= 100;

    // cout << A << " " << BB << endl;

    __int128 r = (__int128)A*BB;

    cout << (int64_t)(r/10000) << endl;

}