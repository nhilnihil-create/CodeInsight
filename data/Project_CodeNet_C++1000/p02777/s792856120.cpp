#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    string u;
    cin >> u;
    if (s == u) {
        a--;
    } else {
        b--;
    }
    cout << a << " " << b << endl;
    return 0;
}