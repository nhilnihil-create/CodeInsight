#include <iostream>
using namespace std;

#define int long long

signed main() {
    int a;
    cin >> a;
    cout << a * (1 + a * (1 + a)) << endl;
    return 0;
}