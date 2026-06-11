#include <iostream>
using namespace std;

int main(void)
{
    char a;
    cin >> a;

    if ('a' <= a && a <= 'z')
    {
        cout << "a";
    }
    if ('A' <= a && a <= 'Z')
    {
        cout << "A";
    }
    return 0;
}