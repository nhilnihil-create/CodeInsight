#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int main(void) {

    int a, b;
    cin >> a >> b;

    printf("%d %d %lf\n", a / b, a % b, static_cast<double>(a) / b);

    return 0;
}