#include<bits/stdc++.h>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    B *= 2;
    if (A-B < 0) cout << 0 << endl;
    else cout << A-B << endl;
    return 0;
}
