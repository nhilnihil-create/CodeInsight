#include<iostream>
#include<vector>
using namespace std;

vector<pair<long long,long long>> prime_factorize(long long n){
    vector<pair<long long,long long>> res;
    for(long long p=2;p*p<=n;++p){
        if(n%p!=0) continue;
        int num=0;
        while(n%p==0){
            n/=p;
            ++num;
        }
        res.push_back(make_pair(p,num));
    }
    if(n!=1) res.push_back(make_pair(n,1));
    return res;
}

int main(){
    long long n;
    cin>>n;
    auto a=prime_factorize(n);
    
    long long ans=0;
    for(auto tp:a){
        long long cnt=tp.second;
        long long temp=0, cur=1;
        while(cnt>=cur) cnt-=cur++, ++temp;
        ans+=temp;
    }

    cout<<ans<<endl;
}