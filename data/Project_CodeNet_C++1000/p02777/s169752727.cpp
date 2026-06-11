#include <bits/stdc++.h>          
using namespace std;               

int main() {
    string S,T,U;
    cin >> S >> T;
    int A,B;
    cin >> A >> B;
    cin >> U;
    int countS=A, countT=B;
    if (S==U) {
        countS--;
    }
    else if (T==U) {
        countT--;
    }
    cout << countS << " " << countT << endl;
}