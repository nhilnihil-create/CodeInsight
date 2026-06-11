#include <iostream>
using namespace std;

int x;
bool dp[1000200];

int main() {
    cin >> x;
    for (bool &i : dp) i = false;
    for (int i = 100; i <= 105; i++) dp[i] = true;
    for (int i = 0; i <= 1000000; i++) {
        if (dp[i]) {
            for (int j = 100; j <= 105; j++) dp[i+j] = true;
        }
    }
    cout << (dp[x] ? 1 : 0) << endl;
    return 0;
}