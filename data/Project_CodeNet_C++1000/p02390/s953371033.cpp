#include <iostream>
using namespace std;

int main()
{
    int a,b,c,base;
    cin >> base;
    
    int h,m,s;

    h = base / 3600;
    base -= 3600 * h;
    m = base / 60;
    s = base % 60;

    cout << h << ":" << m << ":" << s << endl;

}

