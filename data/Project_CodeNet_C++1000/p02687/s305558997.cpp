#include<iostream>
#include<string.h>
int main()
{
    char a[10] = {'\0'};
    std::cin>>a;
    if(strcmp(a,"ABC")){
        std::cout<<"ABC"<<std::endl;
    }
    else{
        
        std::cout<<"ARC"<<std::endl;
    }
    return 0;
}