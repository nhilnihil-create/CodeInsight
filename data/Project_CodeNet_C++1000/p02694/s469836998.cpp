#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()

int main() {
    int64_t X;
    cin >> X;
    int64_t money = 100;
    int64_t count = 0;

    while (money < X) {
        money += money/100;
        count++;
    }
    cout << count << endl;
    return 0;
}