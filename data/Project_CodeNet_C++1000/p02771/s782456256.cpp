#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A == B && C != B) {
        cout << "Yes" << endl;
        return 0;
    } 
    if(A == C && C != B) {
        cout << "Yes" << endl;
        return 0;
    }
    if(B == C && C != A) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}