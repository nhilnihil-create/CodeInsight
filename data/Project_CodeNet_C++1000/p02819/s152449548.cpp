#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int prime(long n);

int main()
{
    long n;
    cin>>n;
    /*if(n==2 || n==3)
    {
        cout<<n;
        return 0;
    }*/
    while(1)
    {
        if(prime(n))
        {
            cout<<n;
            break;
        }
        else
        {
            if(n%2)
        {
            n+=2;
        }
        else
            n++;
        }
    }

    return 0;
}
int prime(long n)
{
    long i;
    int flag=1;
    for(i=2;i<=(n/2);i++)
    {
        if(!(n%i))
        {
            flag=0;
            break;
        }
    }
    return flag;
}
