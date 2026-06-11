#include<iostream>
#include<vector>
#include<map>

void stupid(){
        int N;
    std::cin>>N;
    std::vector<long long>A(N);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
    }
    long long ans=0;
    for(int i=1;i<N;++i){
        for(int j=0;(j+i)<N;++j){
            if(A[j]+A[i+j]==i){
                ans++;
            }
        }
    }
    std::cout<<ans<<std::endl;
}

void correct(){
    int N;
    std::cin>>N;
    std::vector<long long>A(N);
    long long maxA,minA;
    for(int i=0;i<N;++i){
        std::cin>>A[i];
        if(i==0){
            maxA=A[0];
            minA=A[0];
        }else if(maxA<A[i]){
            maxA=A[i];
        }else if(minA>A[i]){
            minA=A[i];
        }
    }
    std::map<long long,long long> L,R;
    for(int i=0;i<N;++i){
        L[i+1+A[i]]++;
        R[i+1-A[i]]++;
    }
    unsigned long long ans=0;
    for(int x=minA;x<=N-minA;++x){
        // std::cout<<"x"<<x<<"r"<<R[x]<<"l"<<L[x]<<std::endl;
        ans+=L[x]*R[x];
    }
    std::cout<<ans<<std::endl;
    return;
}

int main(){
    correct();
}