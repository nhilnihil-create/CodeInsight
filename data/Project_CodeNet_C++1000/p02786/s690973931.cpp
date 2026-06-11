#include <iostream>
using namespace std;
long long attack(long long h) {
    if (h == 1) {
        return 1;
    } else {
        return 2*attack(h/2)+1;
    }
}
int main() {
    long long h;
    cin >> h;
    cout << attack(h) << endl;
}