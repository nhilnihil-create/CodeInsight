#include <iostream>

int main(){
    int S;
    int h,m,s;
    std::cin>>S;
    if(0<=S&S<86400){
    s=S%60;
    m=(S-s)%3600;
    h=(S-m-s)/3600;
    
    
    std::cout<<h<<':'<<m/60<<':'<<s<<std::endl;
    }
}

