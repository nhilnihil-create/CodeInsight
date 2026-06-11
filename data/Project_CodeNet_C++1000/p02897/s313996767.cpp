#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;

    if(n%2 == 0)
    {
        cout << fixed << setprecision(15) << 0.5 << endl;
    }
    else {
        int m = n/2 + 1;
        cout << fixed << setprecision(15) << (double)m/n << endl;
    }
    return 0;
}