#include<iostream>
#include<math.h>
#define pi 2*acos(0)
int main()
{
    int a,b,c;
    int x=0;
    std::cin>>a>>b>>c;

    x = c/a;
    if(a*x>= b){
        std::cout<<"OK"<<std::endl;
    }
    else{
        
        std::cout<<"NG"<<std::endl;
    }
    return 0;
}