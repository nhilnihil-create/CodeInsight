#include <iostream>
using namespace std;
bool isPrime (int);

int main()
{
    int X, i;

    cin>>X;
    for (i=X; !isPrime(i); i++);
    cout<<i;
    return 0;
}

bool isPrime (int a)
{
    int counter=0;
    for (int i=2; i<=a/2; i++)
        if(a%i==0)
            counter++;

    if (counter==0)
        return true;
    else
        return false;
}
