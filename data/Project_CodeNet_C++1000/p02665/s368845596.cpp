#include <bits/stdc++.h>
const long long INF = (1LL<<61);

signed main(void){
    
    long long N;
    std::cin >> N;
    std::vector<long long> A,K(N+1,0ll);
    for(int i=0;i<=N;i++){
        long long a;
        std::cin >> a;
        A.push_back(a);
    }
    
    //N=0の場合だけ分ける
    if(N==0){
        if(A[0]==1){
            std::cout << 1 << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }
        return 0;
    }
    
    //存在しなければtrue
    bool invalid = false;
    
    if(A[0]!=0){
        invalid=true;
    }
    
    //漸化式を解く
    K[0]=1;
    for(int i=0;i<N;i++){
        if(K[i]-A[i]<0)invalid=true;
        K[i+1]=std::min(INF,2ll*(K[i]-A[i]));
    }
    if(K[N]-A[N]<0)invalid=true;
    
    //後ろからも解く
    K[N]=A[N];
    for(int i=N-1;i>=0;i--){
        K[i]=std::min(K[i],K[i+1]+A[i]);
    }
    
    //存在しない
    if(invalid){
        std::cout << -1 << std::endl;
        return 0;
    }
    
    //存在する
    long long Ans=0;
    for(int i=0;i<=N;i++){
        Ans+=K[i];
    }
    std::cout << Ans << std::endl;
    
    return 0;
}
