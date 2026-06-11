#include <iostream>
#include<string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a%2 != b%2) {
        cout << "IMPOSSIBLE";
    } else {
        cout << (a+b)/2;
    }
}