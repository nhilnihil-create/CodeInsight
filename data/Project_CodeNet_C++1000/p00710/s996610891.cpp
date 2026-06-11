#include <iostream>

using namespace std;

int main() {
    int n, r, p, c, top;
    int order[50][2];
    while (true) {
        cin >> n >> r;
        if (n == 0 && r == 0) {
            break;
        }
        top = n;
        for (int i = 0; i < r; ++i) {
            cin >> order[i][0] >> order[i][1];
        }
        for (int i= r - 1; i >= 0; --i) {
            p = order[i][0];
            c = order[i][1];
            if (top > n - p - c + 1) {
                if (top > n - c) {
                    top -= p - 1;
                }
                else {
                    top += c;
                }
            }
        }
        cout << top << endl;
    }
    return 0;
}