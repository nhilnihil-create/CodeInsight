#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;

    do {  
        cin >> a >> b >> c;
    } while ((a < 0 || a > 100) || (b < 0 || b > 100) || (c < 0 || c > 100));

    if (a < b && b < c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return (0);
}