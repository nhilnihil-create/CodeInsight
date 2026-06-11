#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;

    cout << (n >= 10 ? r : r + 100 * (10 - n)) << endl;

    return 0;
}
