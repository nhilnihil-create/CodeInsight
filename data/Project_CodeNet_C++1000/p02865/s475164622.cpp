#include <iostream>

using namespace std;

int main()
{

        int n = 0;
        cin >> n;
        int a = 0;
        if (n % 2) {
                a = n / 2;
        }
        else {
                a = n / 2 - 1;
        }
        cout << a << endl;

        return 0;
}
