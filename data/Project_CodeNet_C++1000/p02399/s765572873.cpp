#include    <iostream>
#include    <cstdio>

using namespace std;

int main() {
    int a, b, d, r;
    double f;

    cin >> a >> b;
    printf("%d %d %.5f\n", a/b, a%b, (double)a/(double)b);

    return 0;
}
