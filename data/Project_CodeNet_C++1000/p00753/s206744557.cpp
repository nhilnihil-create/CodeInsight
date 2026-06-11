#include <iostream>
#include <string.h>
using namespace std;

const int N = 123456;
bool b[2*N+1];

int main() {
    int i, j, n, res;
    memset(b, true, sizeof(b));
    b[0] = b[1] = false;
    for (i=0; i*i<=2*N; i++) {
        if (b[i]) {
            for (j=i+i; j<=2*N; j+=i) {
                b[j] = false;
            }
        }
    }

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        res = 0;
        for (i=n+1; i<=2*n; i++) {
            if (b[i]) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}