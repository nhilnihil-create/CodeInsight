#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    vector<int> A(1, X);
    vector<int> B(1, Y);
    vector<int> C(1, Z);
    
    swap(A, B);
    swap(A, C);

    cout << A.at(0) << " "<< B.at(0) << " "<< C.at(0) << endl;

    return 0;
}