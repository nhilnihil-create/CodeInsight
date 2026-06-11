#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    unsigned long a, b;
    cin >> a >> b;
    
    cout << a/b << ' ' << a%b << ' ';
    cout << fixed << setprecision(5) << a / (double) b << endl;
    
    return 0;
}
