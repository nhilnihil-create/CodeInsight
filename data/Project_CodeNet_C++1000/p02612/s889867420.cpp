#include <iostream>
using namespace std;

int main(void)

{
    int n;
    cin >> n;
    if (1000 - n % 1000 != 1000)
    {
        cout << 1000 - n % 1000 << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}