#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int s;
    cin >> s;

    vector<int> dp(2001);
    dp.at(0) = 1;
    dp.at(1) = 0;
    dp.at(2) = 0;

    for (int i = 3; i <= 2000; i++){
        dp.at(i) = dp.at(i-1) + dp.at(i-3);
        dp.at(i) %= 1000000007;
    }

    cout << dp.at(s);

    //
}
