#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

    while (true) {
        int a, op, b, result;
//        cin >> a >> op >> b;
        scanf("%d %c %d", &a, &op, &b);
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                goto END;
                break;
        }
        printf("%d\n", result);
    }

END:
    return 0;
}