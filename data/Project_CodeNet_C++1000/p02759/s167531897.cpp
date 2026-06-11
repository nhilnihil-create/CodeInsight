#include<iostream>
using namespace std;
int main (void)
{

    int a;

    cin >> a;

    if(a % 2 != 0)
        a = a / 2 + 1;
    else 
        a /= 2;

     cout << a << endl;

    return 0;
}