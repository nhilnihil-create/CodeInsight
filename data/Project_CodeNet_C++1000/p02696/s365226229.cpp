#include<iostream>
#include<cmath>

int main(){
    int A;
    long long B,N;
    long long ans;
    std::cin>>A>>B>>N;
    ans=(A*N)/B-(N/B)*A;
    // for(long long x=B-1;x<=N;x+=B){
    //     long long buf=(A*x)/B-(x/B)*A;
    //     if(ans<buf){
    //         ans=buf;
    //     }
    // }
    long long buf=((N/B)-1)*B+B-1;
    buf=(A*buf)/B-(buf/B)*A;
    if(ans<buf){
        ans=buf;
    }
    std::cout<<ans;
}