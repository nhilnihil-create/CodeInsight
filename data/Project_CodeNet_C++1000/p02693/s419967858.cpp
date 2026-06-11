#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int k,a,b,sum;
    cin>>k>>a>>b;
    sum = (b / k)* k;
    if(a <= sum){
        cout<<"OK";
    }
    else{
        cout<<"NG";
    }
    return 0;
}
