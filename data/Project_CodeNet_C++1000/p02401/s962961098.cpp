#include <iostream>

using namespace std;

int main() {

    int a, b, c;
    string op;

    while(1) {
        cin >> a >> op >> b;
        if (op == "?")
            break;
        else if (op == "+")
            c = a + b;
        else if (op == "-")
            c = a - b;
        else if (op == "*")
            c = a * b;
        else if (op == "/")
            c = a / b;
        else
            continue;
        cout << c << endl;
    }
    return 0;
}