#include<iostream>

int main(){
    int h;
    int w;

    while(true){
        std::cin>>h;
        std::cin>>w;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                std::cout<<"#";
            }
            std::cout<<std::endl;
        }
        if(h==0&&w==0){
            break;
        }
        std::cout<<std::endl;
    }

    return 0;
}