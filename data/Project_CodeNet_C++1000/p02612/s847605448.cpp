#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,sum;
    cin>>n;
    sum=(1000 - n % 1000)%1000;
    cout<<sum<<endl;
    return 0;
}