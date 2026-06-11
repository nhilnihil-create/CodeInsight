#include <iostream>
using namespace std;

int main ()
{
    int s;
    cin >> s;
    int yekan = s % 10;
    int dahgan = s / 10 % 10;
    int sadgan = s / 100 % 10;
    int hezargan = s / 1000 % 10;
    if (yekan == dahgan || dahgan == sadgan || sadgan == hezargan)
        cout << "Bad";
    else
        cout << "Good";
}
