#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph=vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

ll power(ll A,ll B,ll M){
    if(B==0){
        return 1;
    }
    else if(B%2==0){
        ll s=power(A,B/2,M);
        return (s*s)%M;
    }
    else{
        return ((A%M)*power(A,B-1,M))%M;
    }
}

int main(){
    ll N,K;
    cin>>N>>K;
    ll T=min(K,N-K+1);
    vector<ll>comb1(T);
    vector<ll>comb2(K);
    ll MOD=1000000007;
    comb1.at(0)=(N-K+1)%MOD;
    comb2.at(0)=(K-1)%MOD;
    for(long long i=1;i<T;i++){
        comb1.at(i)=(((comb1.at(i-1)*power(i+1,MOD-2,MOD))%MOD)*((N-K+1-i)%MOD))%MOD;
    }
    for(long long i=1;i<K;i++){
        comb2.at(i)=(((comb2.at(i-1)*power(i+1,MOD-2,MOD))%MOD)*((K-1-i)%MOD))%MOD;
    }
    if(T==K){
        rep(i,K){
            if(i==0){
                cout<<comb1.at(i)%MOD<<endl;

            }
            else{
                cout<<(comb1.at(i)*comb2.at(i-1))%MOD<<endl;
            }
        }
    }
    else{
        rep(i,T){
            if(i==0){
                cout<<comb1.at(i)%MOD<<endl;

            }
            else{
                cout<<(comb1.at(i)*comb2.at(i-1))%MOD<<endl;
            }
        }
        rep(j,K-T){
            cout<<0<<endl;
        }
    }
}

