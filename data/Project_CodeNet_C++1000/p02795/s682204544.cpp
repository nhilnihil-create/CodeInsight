#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    int x = max(h, w);
    int cnt = n / x;
    if (n % x != 0)
        cnt++;

    cout << cnt;
    return 0;
}
