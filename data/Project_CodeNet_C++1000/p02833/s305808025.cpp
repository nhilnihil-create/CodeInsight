#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long cnt = 0;
    cin >> num;

    // 奇数
    if (num % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    num /= 2;
    while (num > 0) {
        cnt += num / 5;
        num /= 5;
    }

    cout << cnt << endl;

    //
}