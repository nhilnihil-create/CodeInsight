#include<iostream>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    ll m,n;cin>>m>>n;
    ll res=1;
    while(n>0){
        if(n&1) res=res*m%mod;
        m=m*m%mod;
        n>>=1;
    }
    cout<<res<<endl;
    return 0;
}
