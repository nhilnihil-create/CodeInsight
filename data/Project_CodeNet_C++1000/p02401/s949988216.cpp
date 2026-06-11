#include <iostream>
using namespace std;

int main() {
    int A[10000], i, a, b, t;
    string op;
    for (i = 0; i < 10000; i++) {
        cin >> a >> op >> b;
        if (op == "+") {
            t = a + b;
            A[i] = t;
        } else if (op == "-")  {
            t = a - b;
            A[i] = t;
        } else if (op == "*")  {
            t = a * b;
            A[i] = t;
        } else if (op == "/")  {
            t = a / b;
            A[i] = t;
        } else {
            break;
        }
    }
    for (int j = 0; j < i; j++) cout << A[j] << endl;
    return 0;
}