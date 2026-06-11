#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {

    int a, b;
    cin >> a >> b;

//    cout << (a / b) << " "
//         << (a % b) << " "
//         << (static_cast<double>(a) / b)
//         << endl;
    printf("%d %d %lf\n", (a/b), (a%b), (static_cast<double>(a)/b));

//    int d = a / b;
//    int r = a % b;
//    double f = static_cast<float>(a) / b;
//    printf("%d %d %lf\n", d, r, f);

    return 0;
}