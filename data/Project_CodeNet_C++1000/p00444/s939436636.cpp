#include<iostream>
using namespace std;

int main()
{
    int n;

    while( cin >> n )
    {
        if( n == 0 )
            break;
        int c = 1000 - n;
        int sum = 0;
        sum = c / 500 + c % 500 / 100 + c % 500 % 100 / 50 + c % 500 % 100 % 50 / 10 + c % 500 % 100 % 50 % 10 / 5 + c % 500 % 100 % 50 % 10 % 5;
        cout << sum << endl;
    }

    return 0;
}
