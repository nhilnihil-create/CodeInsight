#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x >= 2000) {
        cout << 1 << endl;
    } else {
        int res = 0;
        for (int a = 0; a < 20; a++) {
            for (int b = 0; b < 20; b++) {
                for (int c = 0; c < 20; c++) {
                    for (int d = 0; d < 20; d++) {
                        for (int e = 0; e < 20; e++) {
                            for (int f = 0; f < 20; f++) {
                                if (x == a*100 + b*101 + c*102 + d*103 + e*104 + f*105) res = 1;
                            }
                        }
                    }
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
