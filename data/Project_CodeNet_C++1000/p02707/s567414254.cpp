#include<iostream>
#include<map>

int main(){
    int N;
    std::map<int,int>m;
    std::cin>>N;
    for(int i=0;i<N-1;++i){
        int buf;
        std::cin>>buf;
        m[buf-1]++;
    }
    for(int i=0;i<N;++i){
        std::cout<<m[i]<<std::endl;
    }
}