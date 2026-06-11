#include <iostream>
using namespace std;
int main(void){
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    while (A >= B) {
        B *= 2;
        K--;
    }
    while (B >= C) {
        C *= 2;
        K--;
    }
    if (K >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
