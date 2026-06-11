#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    int aria = a * b;
    int rec = (a + b) * 2;
    cout << aria << " " <<rec << endl;
    return 0;
}