#include<iostream>
#include<vector>

void stupid(){
    int N;
    std::cin>>N;
    std::vector<unsigned long long>A(N);
    unsigned long long totalXOR=0x0000;
    for(auto& a:A){
        std::cin>>a;
    }
    for(int i=0;i<N;++i){
        totalXOR^=A[i];
    }
    for(int i=0;i<N;++i){
        unsigned long long buf=totalXOR^A[i];
        std::cout<<buf<<" ";
    }
}
int main(){
    stupid();
    return 0;
}