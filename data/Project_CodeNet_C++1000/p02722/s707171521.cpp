#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<long long> f(long long N){
    vector<long long> res;
    long long i;
    for(i=1;i*i<N;i++){
        if(i>1000000)cout<<i<<endl;
        if(N%i==0){
            res.push_back(i);
            res.push_back(N/i);
        }
    }
    if(i*i==N){
        res.push_back(i);
    }
    return res;
}

int g(long long p,long long N){
    while(N%p==0){
        N/=p;
    }
    if(N%p==1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    long long N;
    cin>>N;

    auto v=f(N-1);
    auto w=f(N);
    long long ans=v.size()-1;
    //for(auto p:w){cout<<p<<" ";}cout<<endl;
    for(auto p:w){
        if(p!=1){
            ans+=g(p,N);
        }
    }
    cout<<ans<<endl;

    
    return 0;
}