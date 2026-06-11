#include <iostream>
using namespace std;

const int MX = 246913;
bool isPrime[MX];
int cum[MX];

int main() {
    for (int i=0; i<MX; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<MX; ++i) {
        if ( ! isPrime[i]) continue;
        for (int j=2*i; j<MX; j+=i) {
            isPrime[j] = false;
        }
    }
    cum[0] = 0;
    for (int i=1; i<MX; ++i) {
        cum[i] = cum[i-1] + (int)isPrime[i];
    }
    int n;
    while (cin >> n, n) {
        cout << cum[2*n] - cum[n] << endl;
    }
    return 0;
}