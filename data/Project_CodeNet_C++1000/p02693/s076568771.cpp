#include <bits/stdc++.h>
using namespace std;

long K, A, B;

int main(void) {

    cin >> K >> A >> B;

    bool f = false;

    for (long i = A; i <= B; i++) {
        if (i%K == 0) {
            f = true;
            break;
        }
    }

    cout << (f ? "OK" : "NG") << endl;

    return 0;

}