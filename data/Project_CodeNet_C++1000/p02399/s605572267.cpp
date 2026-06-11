#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a / b << " ";
    cout << a % b << " ";
    cout << fixed << setprecision(8);
    cout << static_cast<double>(a) / b << "\n";
}