//
//  main.cpp
//  三井住友_2019_B
//
//  Created by Joe Mori on 2020/05/27.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    long long int a,b,c;
    std::cin>>a;
    b=a*100/108;
    c=(a+1)*100/108;
    b=b*1.08;
    c=c*1.08;
//    std::cout<<b<<" "<<c<<std::endl;
    if(b==a){
        b=b/1.08;
        std::cout<<b<<std::endl;
    }else if(c==a){
        c=c/1.08+1;
        std::cout<<c<<std::endl;
    }else
        std::cout<<":("<<std::endl;
    return 0;
}
