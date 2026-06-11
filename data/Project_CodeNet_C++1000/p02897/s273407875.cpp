#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    float sum,a =0,n;
    cin>>n;
    for(int i =1; i<= n; i++){
        if((i+1)%2 == 0){
            a++;
        }
    }
    sum = a/n;
    cout<<sum;

    return 0;
}
