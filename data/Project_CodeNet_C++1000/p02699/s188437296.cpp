#include<iostream>
#include<math.h>
int main()
{
    int a,b;
    std::cin>>a>>b;
    if(a>b){
        std::cout<<"safe"<<std::endl;
    }
    else{
        std::cout<<"unsafe"<<std::endl;
    }
    return 0;
}