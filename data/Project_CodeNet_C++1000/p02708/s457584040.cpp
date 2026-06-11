#include<iostream>
#include<vector>

int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<unsigned long long> maxs(N+2),mins(N+2);
    maxs[N+1]=N*((unsigned long long)N+1)/2;
    mins[0]=0;
    for(unsigned long long i=1;i<=N+1;++i){
        mins[i]=(i-1)+mins[i-1];
        maxs[N-i+1]=maxs[N-i+2]-(i-1);
    }

    // for(int i=0;i<=N+1;++i){
    //     std::cout<<maxs[i]<<" ";
    // }
    // std::cout<<std::endl;
    // for(int i=0;i<=N+1;++i){
    //     std::cout<<mins[i]<<" ";
    // }
    // std::cout<<std::endl;
    
    unsigned long long ans=0;
    for(int i=K;i<=N+1;++i){
        // std::cout<<maxs[i]<<" "<<mins[i]<<std::endl;
        ans=(ans+(maxs[i]-mins[i])+1)%1000000007;
    }
    std::cout<<ans<<std::endl;
}