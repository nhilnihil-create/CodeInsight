#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int k, x;
    cin >> k >> x;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        if (i == -1000001) {
            for (int j = 0; j < k - i; j++) {
                //
                cout << x+j << " ";
            }
        }

        cout << x-k+i+1 << " ";
        cnt++;
    }

    for (int i = 1; i < k; i++) {
        if (i == 1000001) {
            for (int j = 1; j < k - i; j--) {
                //
                cout << x-j << " ";
            }
        }

        cout << x+i << " ";
    }
}