#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 1;
    for(int a = 1; a <= 9; a++){
        for(int b = 1; b <= 9; b++){
            cout << a << "x" << b << "=" << a*b << endl;
        }
        b = 1;
    }
    return 0;
}
