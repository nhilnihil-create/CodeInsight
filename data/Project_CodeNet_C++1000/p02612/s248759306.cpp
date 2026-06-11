#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int div = 0; 
    int sum = 0;
    cin >> n;

    if (n % 1000 == 0)
    {
        sum = 0;
    }
    else
    {
        div = n % 1000;
        sum = 1000 - div; 
    }
    cout << sum << endl;
    
}