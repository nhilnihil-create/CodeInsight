#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],prime[N],k,vis[N];
int n,flag=0;
bool isprime[N];
void Prime(){
    fill(isprime,isprime+N,1);
    k=0;
    prime[1]=0;
    for(ll i=2;i<N;i++){
        if(isprime[i]){
            prime[k++]=i;
            for(ll j=2;i*j<N;j++)
                isprime[i*j]=0;
        }
    }
}

void solve(ll n){
    for(ll i=0;i<k&&prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            if(vis[prime[i]]==0) vis[prime[i]]=1;
            else{
                flag=1;
                return;
            }
            while(n%prime[i]==0){
                n/=prime[i];
            }
        }
    }
    if(n>1){
         if(vis[n]==0) vis[n]=1;
        else{
            flag=1;
            return;
        }
    }
}

inline ll gcd(ll a,ll b)
{
    return (a%b==0)?b:gcd(b,a%b);
}

int main(){
    Prime();
    cin>>n;
    ll GCD=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(!flag) solve(a[i]);
        if(GCD==0) GCD=a[i];
        else GCD=gcd(GCD,a[i]);
    }
    if(!flag) printf("pairwise coprime");
    else if(flag&&GCD==1) printf("setwise coprime");
    else printf("not coprime");
}