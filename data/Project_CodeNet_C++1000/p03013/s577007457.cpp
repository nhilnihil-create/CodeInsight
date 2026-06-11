#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> a(N+1,0);
    for(ll i=1;i<=M;i++){
        ll temp;
        cin>>temp;
        a[temp]=-1;
    }
    a[0]=1;
    if(a[1]!=-1){
        a[1]=1;
    }
    for(ll i=2;i<=N;i++){
        if(a[i]==-1){
            continue;
        }
        a[i]=0;
        if(a[i-1]!=-1){
            a[i]+=a[i-1];
            a[i]=a[i]%MOD;
        }
        if(a[i-2]!=-1){
            a[i]+=a[i-2];
            a[i]=a[i]%MOD;
        }
    }
    cout<<a[N]%MOD<<endl;
    return 0;
}