#include <iostream>
using namespace std;

int num[300000];

int main(void) {
    for (int i = 0; i < 300000; i++) {
        num[i] = 1;
    }
    num[0] = 0;
    num[1] = 0;

    for (int i = 2; i < 300000; i++) {
        for (int j = 2; i*j < 300000; j++) {
            num[i*j] = 0;
        }
    }

    int n;
    while (cin >> n, n) {
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++) {
            cnt += num[i];
        }

        cout << cnt << endl;
    }
    return 0;
}