#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    printf("a %s b\n", (a == b ? "==" : (a > b ? ">" : "<")));
    return 0;
}