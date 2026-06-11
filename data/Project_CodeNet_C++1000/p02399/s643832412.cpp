#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double d;
    d = (1.0*a) / b;

    cout << a/b << ' ' << a%b << ' ';
    printf("%.8lf\n",d);

    return 0;
}
