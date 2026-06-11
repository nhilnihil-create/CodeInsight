#include <iostream>

int main()
{
 int a,b,c,d;
 std::cin>>a>>b>>c>>d;
    while(1>0){
        c=c-b;
        if(c<=0){
         std::cout << "Yes" << std::endl;
            return 0;
        }
        if(c>0){
            a=a-d;
            if(a<=0){
             std::cout << "No" << std::endl;
             return 0;
            }
        
            
        }
    }
    
}