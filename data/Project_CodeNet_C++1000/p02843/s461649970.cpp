#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int DP[100001];

int main() {
    int X;
    cin >> X;
    DP[0] = 1;
    for (int i = 100; i < 106; i++) {
        DP[i] = 1;
    }

    for (int i = 106; i <= 100000; i++) {
        DP[i] = max({ DP[i - 100],DP[i - 101],DP[i - 102],DP[i - 103],DP[i - 104],DP[i - 105] });
    }
    cout << DP[X];
}