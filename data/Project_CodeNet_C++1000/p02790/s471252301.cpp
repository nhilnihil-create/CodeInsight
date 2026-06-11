#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    string s1(b, a + '0'), s2(a, b + '0');
    if (s1 < s2) {
        cout << s1 << "\n";
    } else {
        cout << s2 << "\n";
    }
}