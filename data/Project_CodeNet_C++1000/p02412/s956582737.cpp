#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    while (1) {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    int sum = i + j + k;
                    if (sum == x) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
