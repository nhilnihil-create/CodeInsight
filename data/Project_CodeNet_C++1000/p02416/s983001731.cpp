#include<iostream>
#include<string>

int main(void){
    std::string number;
    int sum;
    while(1){
        std::cin>>number;
        sum=0;
        if(number=="0") break;
        for(int i=0;i<number.size();i++){
            sum+=number[i]-'0';
        }
        std::cout<<sum<<std::endl;
    }
    return 0;
}