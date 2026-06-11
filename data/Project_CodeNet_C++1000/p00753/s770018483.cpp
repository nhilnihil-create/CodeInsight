#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> isprime(2 * n + 1, 1);
        int cnt = 0;
        for (int i = 2; i <= 2 * n; i++) {
            if (not(isprime[i] == 1)) {
                continue;
            }
            if (i > n) {
                cnt++;
            }
            for (int j = 2; i * j <= 2 * n; j++) {
                isprime[i * j] = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}