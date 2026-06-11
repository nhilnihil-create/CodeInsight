#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    double f1 = (double)a/b;
 
    cout << fixed;  
    cout << setprecision(10) << a/b << " " << a%b << " " << f1 << endl;
    return 0;
}

