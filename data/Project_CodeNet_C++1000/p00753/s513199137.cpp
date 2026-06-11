#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int N;

    while (cin >> N, N) {
        int ans = 0;
        for (int i = N + 1; i <= 2 * N; i++) {
            bool flag = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}