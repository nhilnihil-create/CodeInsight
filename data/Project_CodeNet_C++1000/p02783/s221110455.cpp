#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int h,a,sum=0;
    cin>>h>>a;
    for(int i =1; h > 0;i++){
        h= h-a;
        sum++;
    }
    cout<<sum;

    return 0;
}