#include<string>
#include<iostream>
#include<algorithm>

void print(std::string str,int a,int b){
    std::cout<<str.substr(a,b-a+1)<<std::endl;
}

int main(void){
    std::string str,instruction;
    int a,b,q;
    std::cin>>str;
    std::cin>>q;
    while(q-->0){
        std::cin>>instruction>>a>>b;
        switch(instruction[2]){
            case 'i':
                print(str,a,b);
                break;
            case 'v':
                std::reverse(str.begin()+a,str.begin()+b+1);
                break;
            case 'p':
                std::string p;
                std::cin>>p;
                str.replace(a,b-a+1,p);
                break;
        }
    }
    

    return 0;
}
