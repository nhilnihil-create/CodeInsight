#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
using ll=long long;

vector<bool> isprime(1000005);

void eratos(int n){
    for(int i=0;i<n+1;i++){
        isprime[i]=true;
    }
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            int j=i+i;
            while(j<=n){
                isprime[j]=false;
                j=j+i;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;

    ll ans=0;
    eratos(1000005);
    for(ll i=2;i<1000006;i++){
        if(!isprime[i]) continue;
        ll j=i;
        while(1){
            if(n%j==0){
                n/=j;
                ans++;
                j*=i;
            }
            else{
                break;
            }                        
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1){
        ans++;
    }

    cout<<ans<<endl;
}