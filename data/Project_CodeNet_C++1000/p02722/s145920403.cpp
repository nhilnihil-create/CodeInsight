#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//ABC161 F
/*
long long replace(long long n,long long i){

    while(n>=i){

        if(n%i==0)n/=i;

        else{
            n-=i;
        }
    
    }
    return n;
}
*/
vector<long long>prime1;
vector<long long>prime2;

vector<long long> eratos(long long n,vector<long long>prime){
    long long tmp=sqrt(n);
    for(long long i=2;i<=tmp;i++){
        if(n%i==0){
            prime.push_back(i);
            //while(n%i==0)n/=i;
            //prime.push_back(n/i);
        }
    }
    //if(n!=1)prime.push_back(n);
    return prime;
}

long long  cal(long long n){

    long long tmp=sqrt(n);

    long long ret=1;
    for(long long i=2;i<=tmp;i++){
    long long now=1;
        while(n%i==0){
            n/=i;
            now++;
        }
        ret*=now;
    }
    if(n!=1){
        ret*=2;
    }

    return ret;
}

int main(){

    long long n;
    cin>>n;

    long long ans=1;
    if(n==2){
        cout<<"1"<<endl;
        return 0;
    }
    
    prime1=eratos(n,prime1);
    
    //nの約数について
    for(long long i=0;i<prime1.size();i++){
        long long p=n/prime1[i];

        //cout<<prime1[i]<<endl;
        //cout<<p<<endl;
        if(p%prime1[i]==1){
            ans++;
        }
        else if(p==prime1[i]){
            ans++;
        }
        else if(p%prime1[i]==0){
            
            while(p%prime1[i]==0){
                p/=prime1[i];
            }
            p%=prime1[i];
            if(p==1)ans++;
        }
    }
    //cout<<ans<<endl;
    //nの約数以外について
    
    ans+=cal(n-1);
    ans--;
    
    cout<<ans<<endl;
    return 0;

}
/*

*/
