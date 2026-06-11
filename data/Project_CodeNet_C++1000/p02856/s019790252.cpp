#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    long long digit = 0;
    long long digit_sum = 0;
    for (int i = 0; i < m; i++) {
        long long d, c;
        cin >> d >> c;
        digit += c;
        digit_sum += d * c;
    }
    
    long long ans = (digit_sum <= 9 ? 0 : ((digit_sum - 10) / 9 + 1)) + (digit - 1);
    cout << ans << endl;
}