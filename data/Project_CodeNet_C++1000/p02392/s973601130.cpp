#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {

    int a, b, c;
    cin >> a >> b >> c;

    if (a < b && b < c) {
        puts("Yes");
    }
    else {
        puts("No");
    }

    return 0;
}