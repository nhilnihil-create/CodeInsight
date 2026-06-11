#include <iostream>
using namespace std;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    if (B/K - (A-1)/K >= 1) cout << "OK" << endl;
    else cout << "NG" << endl;
}