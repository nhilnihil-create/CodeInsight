#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll N=1e6+1;

ll gcd(ll a,ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll fact[N];
bool prime[N];

void sieve(){
    for(ll i=2;i<N;i++){
        if(prime[i]==true){
            for(ll j=i*i;j<=N;j+=i){
                prime[j]=false;
                fact[j]=i;
            }
        }
    }
}

int main(){
    ll n;
    cin>>n;
    ll a[n],ans=0;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1])
            ans+=a[i-1]-a[i],a[i]=a[i-1];
    }
    cout<<ans<<"\n";
    return 0;
}
