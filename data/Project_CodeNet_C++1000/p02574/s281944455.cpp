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
    ll a[n];
    memset(prime,true,sizeof(prime));
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<N;i++)
        fact[i]=i;
    sieve();

    set<ll>pair;
    ll flag=0;
    for(ll i=0;i<n;i++){
        ll temp=a[i];
        while(temp!=1){
            //cout<<fact[temp]<<" ";
            if(!pair.count(fact[temp]))
                pair.insert(fact[temp]);
            else{
                flag=1;
                break;
            }
            ll j=fact[temp];
            while(temp%j==0)
                temp/=j;
        }
    }
    ll temp=a[0];
    for(int i=1;i<n;i++){
        temp=gcd(temp,a[i]);
    }
    //cout<<temp<<" ";
    if(flag==0) cout<<"pairwise coprime \n";
    else if(temp==1) cout<<"setwise coprime \n";
    else cout<<"not coprime \n";
    return 0;
}
