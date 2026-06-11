#include <iostream>

using namespace std;

bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}


int main()
{
    int x;
    scanf("%d",&x);
    while(true)
    {
     if(prime(x)){
        printf("%d\n",x);
        return 0;}
    x++;
    }
    return 0;
}