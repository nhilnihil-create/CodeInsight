#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,hako=0;
    cin >> A >> B >> C;

    hako = B;
    B = A;
    A = hako;

    cout << C << ' ' << B  << ' ' << A << endl;
}