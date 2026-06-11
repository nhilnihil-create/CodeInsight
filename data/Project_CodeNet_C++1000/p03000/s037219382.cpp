#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int ret = 1, now = 0;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        now += l;
        if (now <= x)ret++;
    }

    cout << ret << endl;
    return 0;
}