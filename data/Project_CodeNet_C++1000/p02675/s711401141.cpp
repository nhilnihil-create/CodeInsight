#include <iostream>
using namespace std;

const double Pi = 3.1415926;

int main()
{
    long long n;
    cin >> n;
    n = n % 10;
    if (n == 3)
        cout << "bon";
    else if (n == 0 || n == 1 || n == 6 || n == 8)
        cout << "pon";
    else
        cout << "hon";

    return 0;
}