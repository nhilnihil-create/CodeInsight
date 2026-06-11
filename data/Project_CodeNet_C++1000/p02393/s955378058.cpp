#include <iostream>

int main(){
    int a,b,c;
    std::cin >> a >> b ;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
    std::cin >> c;
    if(c<a) std::cout << c << " " << a << " " << b << std::endl;
    else if(c<b) std::cout << a << " " << c << " " << b << std::endl;
    else std::cout << a << " " << b << " " << c << std::endl;

    return 0;
    }
