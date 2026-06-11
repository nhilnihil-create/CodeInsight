#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ret = 0;
    ret += 1 * min(a, k), k -= min(a, k);
    ret += 0 * min(b, k), k -= min(b, k);
    ret += -1 * min(c, k), k -= min(c, k);
    cout << ret << endl;
    return 0;
}