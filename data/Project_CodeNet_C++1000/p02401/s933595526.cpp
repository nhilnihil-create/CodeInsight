#include <iostream>
#include <string>
using namespace std;

int main()
{
    while (true) {
        int a, b;
        string op;
        cin >> a >> op >> b;
        if (op == "+") {
            cout << a + b << "\n";
        }
        else if (op == "-") {
            cout << a - b << "\n";
        }
        else if (op == "*") {
            cout << a * b << "\n";
        }
        else if (op == "/") {
            cout << a / b << "\n";
        }
        else break;
    }
}