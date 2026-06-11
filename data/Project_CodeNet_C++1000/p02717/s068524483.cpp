#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, temp;
    cin >> A >> B >> C;

    temp = B;
    B = A;
    A = temp;

    temp = C;
    C = A;
    A = temp;
    cout << A << " " << B << " " << C << endl;


}
