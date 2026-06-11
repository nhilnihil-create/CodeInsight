#include <iostream>
using namespace std;

int compareValue(int a, int b)
{
    cout << "a ";
    if (a < b)      cout << "<";
    else if (a > b) cout << ">";
    else            cout << "==";
    cout << " b" << endl;
}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    compareValue(a, b);
    
    return 0;
}