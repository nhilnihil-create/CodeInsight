#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((a - b) >= c){
        cout<<"0";
    }
    else{
        cout<<c-(a-b);
    }


    return 0;
}