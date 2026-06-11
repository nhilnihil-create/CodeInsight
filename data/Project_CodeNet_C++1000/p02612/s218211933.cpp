#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >>a;
    if (1000-a%1000 != 1000)
    {
        cout <<1000-a%1000;
    }
    else {cout << 0;}

    return 0;
}