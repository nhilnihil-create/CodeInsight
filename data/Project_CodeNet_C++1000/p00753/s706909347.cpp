#include "bits/stdc++.h"

using namespace std;
int main(void){
    int n;
    while (cin >> n && n) {
        int count = n != 1 ? 0 : 1;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (i % 2 == 0) continue;
            int e = sqrt(i);
            bool p = true;
            for (int j = 2; j <= e; ++j) {
                if (i % j == 0) {
                    p = false;
                    break;
                }
            }
            if (p) ++count;
        }
        cout << count << endl;
    }
    return EXIT_SUCCESS;
}