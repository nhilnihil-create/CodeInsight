#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n;cin>>n;
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
    ll an=2;
    for(ll i=2;i*i<=n;i++){
        ll N=n;
        if(N%i!=0)continue;
        while(N%i==0){
            N/=i;
        }
        if(N%i==1)an++;
    }
    for(ll i=2;i*i<=n-1;i++){
        if((n-1)%i==0){
            if(i*i==n-1)an++;
            else an+=2;
        }
    }
    cout<<an<<endl;
}

    







