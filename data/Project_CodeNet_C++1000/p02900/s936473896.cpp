#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll gcd(ll a,ll b){
    if(b%a==0) return a;
    else return gcd(b%a,a);
}
ll p[10000];
ll pp=0;
map<ll,ll> prime_factor(ll n){
    map<ll,ll> res;
    for(ll i=2;i*i<=n;i++){
        bool w=true;
        while(n%i==0){
            res[i]++;
            n=n/i;
            if(w){
                w=false;
                p[pp]=i;
                pp++;
            }
        }
    }
    if(n!=1){
        res[n]=1;
        p[pp]=n;
        pp++;
    }
    return res;
}
int main(void){
    ll a,b;
    cin>>a>>b;
    ll g=gcd(a,b);
    map<ll,ll> M=prime_factor(g);
    cout<<pp+1<<endl;
    
}
