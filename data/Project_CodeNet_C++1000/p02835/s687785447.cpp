#include <iostream>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    if (a[0] + a[1] + a[2] >= 22) cout << "bust" << endl;
    else cout << "win" << endl;

}