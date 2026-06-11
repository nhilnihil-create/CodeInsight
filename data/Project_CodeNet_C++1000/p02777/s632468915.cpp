#include <bits/stdc++.h>
using namespace std;

int main(){
    string red, blue, col;
    int A, B;
    cin >> red >> blue;
    cin >> A >> B;
    cin >> col;
    if (col == red){
        cout << A-1 << " " << B << endl;
    }
    else{
        cout << A << " " << B-1 << endl;
    }
}