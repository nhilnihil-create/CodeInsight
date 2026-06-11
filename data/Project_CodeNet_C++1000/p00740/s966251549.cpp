#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;

    for (;;) {
        cin >> n >> p;
        if (n == 0 && p == 0) break;

        vector<int> vi(n, 0);
        int i = 0;
        for (;;) {
            if (p > 0) {
                vi[i]++;
                p--;
            } else {
                bool win = true;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (vi[j] > 0) win = false;
                }

                if (win) {
                    cout << i << endl;
                    break;
                } else {
                    p += vi[i];
                    vi[i] = 0;
                }
            }

            i = (i + 1) % n;
        }
    }
}