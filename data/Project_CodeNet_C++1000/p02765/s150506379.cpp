#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int n,a,r;
    cin>>n>>r;

    if(n < 10){
        a = 100*(10-n);
        a = a+r;
    }
    else{
        a = r;
    }
    cout<<a;

    return 0;
}