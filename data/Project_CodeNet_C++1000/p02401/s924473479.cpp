#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int a,b;
    char op;
    while(1) {
        cin >> a >> op >> b;
        if (op == '?') break;
        if (op == '+') cout << a+b << endl;
        if (op == '-') cout << a-b << endl;
        if (op == '*') cout << a*b << endl;
        if (op == '/') cout << a/b << endl;
    }
    return 0;
}