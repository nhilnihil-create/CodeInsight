#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t, u;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    cin >> u;

    a -= s == u;
    b -= t == u;
    cout << a << ' ' << b << endl;
}

