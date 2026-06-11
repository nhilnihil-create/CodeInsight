#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 0 && s.substr(0, n/2) == s.substr(n/2, n/2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}