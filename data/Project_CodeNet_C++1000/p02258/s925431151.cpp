#include <iostream>
using namespace std;

int main(void) {
    int n, m, ret, t, i;
    ret = -1234567890;
    cin >> n;
    cin >> m;

    for (i = 1; i < n; i++) {
        cin >> t;
        ret = max(ret, t - m);
        m = min(m, t);
    }

    cout << ret << endl;
    return 0;
}