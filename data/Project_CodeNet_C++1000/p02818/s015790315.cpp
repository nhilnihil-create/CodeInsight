#include <iostream>

using namespace std;
#define ll long long

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    if(K > A) {
        cout << 0 << " " << max(0LL, B - (K - A)) << endl;
    } else {
        cout << A - K << " " << B << endl;
    }
    return 0;
}