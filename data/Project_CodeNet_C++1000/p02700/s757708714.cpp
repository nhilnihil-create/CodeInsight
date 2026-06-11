#include<iostream>
int main()
{
    int a,b,c,d;
    std::cin >> a >> b >> c >> d; 
    while (0<1){
        c-=b;
        if (c<=0){
            std::cout << "Yes" << std::endl;
            return 0;
        }
        
        a-=d;
        if (a<=0){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
}