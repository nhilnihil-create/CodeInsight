#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;cin>>n;
    if(n==2){
        cout<<1<<endl;
    }
    else if(n==3){
        cout<<2<<endl;
    }
    else{
    long long ans=2;
    for(long long i=2;i*i<=n;++i){
        long long m=n;
        if(m%i==0){
            while(m%i==0){
                m/=i;
            }
            if(m%i==1)ans++;
        }
    }
    for(long long i=2;i*i<=n-1;++i){
        long long m=n-1;
        if(m%i==0){
            ans++;
            if(m/i!=i)ans++;
        }
    }
    cout<<ans<<endl;}
}
