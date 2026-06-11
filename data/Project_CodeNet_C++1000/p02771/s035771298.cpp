#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int poor = 0;
    if (A == B && B != C) poor = 1;
    if (B == C && C != A) poor = 1;
    if (C == A && A != B) poor = 1;
    if (poor == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}