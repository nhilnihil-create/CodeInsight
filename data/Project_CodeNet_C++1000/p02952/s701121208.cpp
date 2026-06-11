#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l = log10(n);
    int x = 0;
    int res = 0;
    int a;
    while (pow(10, x+1) <= n) {
        a = int(log10(pow(10, x)));
        if (a % 2 == 0 || x == 0) res += (9 * pow(10, x));
        x++;
    }

    if (int(log10(n)) % 2 == 0) res += (n - pow(10, log10(pow(10, x))) + 1) ;

    cout << res << endl;
}