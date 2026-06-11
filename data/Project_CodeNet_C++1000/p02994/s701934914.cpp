#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int mi = 114541919, ret = 0;
    for (int i = 0; i < n; i++) {
        if (abs(mi) > abs(l + i))mi = l + i;
        ret += l + i;
    }

    cout << ret - mi << endl;
    return 0;
}