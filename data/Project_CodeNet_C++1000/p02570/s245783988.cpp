#include <iostream>
using namespace std;
int main() {
    int d, t, s;
    cin >> d >> t >> s;
    if((float)d / s > t) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
    return 0;
}
