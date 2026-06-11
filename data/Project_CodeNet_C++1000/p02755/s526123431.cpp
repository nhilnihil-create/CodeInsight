#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int A, B;
    cin >> A >> B;

    vector<int> xB(10);
    for (int i=0; i<10; i++) {
        xB[i] = 10*B+i;
    }

    int ans = -1;
    vector<int> xA(12);
    if (A%2 == 0) {
        for (int i=0; i<12; i++) {
            xA[i] = 100*A/8+i;
        }
        xA.push_back(100*A/8+12);
        for (int i=0; i<10; i++) {
            for (int j=0; j<13; j++) {
                if (xA[j] == xB[i]) {
                    ans = xB[i];
                    cout << ans << endl;
                    exit(0);
                }
            }
        }
    }

    if (A%2 != 0) {
        for (int i=0; i<12; i++) {
            xA[i] = (100*(A+1)-96)/8+i;
        }

        for (int i=0; i<10; i++) {
            for (int j=0; j<12; j++) {
                if (xA[j] == xB[i]) {
                    ans = xB[i];
                    cout << ans << endl;
                    exit(0);
                }
            }
        }
    }
    cout << ans << endl;
}