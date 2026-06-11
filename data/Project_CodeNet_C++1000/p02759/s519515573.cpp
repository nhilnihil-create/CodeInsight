#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int n,a;
    cin>>n;
    if(n % 2 == 1){
        n=n-1;
        a= n/2;
        a=a+1;
    }
    else{
        a = n/2;
    }
    cout<<a;
    return 0;
}