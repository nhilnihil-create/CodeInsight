#include<iostream>
int main()
{
    int a, b, c, d;
    int sum = 0;
    std::cin >> a >> b >> c >> d;
    sum = a + b + c + d;  
    std::cin >> a >> b >> c >> d;
    if(sum < (a + b + c + d)){
        std::cout << (a + b + c + d)  << std::endl;
    }
    else{
        std::cout << sum << std::endl; 
    }
}