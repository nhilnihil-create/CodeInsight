#include <iostream>
#include<string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    c-= a - b;
    if(c > 0) {
        cout << c;
    } else {
        cout << 0;
    }
}