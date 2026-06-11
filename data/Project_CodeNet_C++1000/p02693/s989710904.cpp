#include <iostream>
using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;

    if (a % k == 0) cout << "OK" << endl;
    else if (a + (k - a % k) <= b) cout << "OK" << endl;
    else cout << "NG" << endl;

}