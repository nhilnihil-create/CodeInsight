#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],prime[N],vis[N];
int n,flag=0,k;
bool isprime[N];

void Prime()
{ 	memset(isprime,1,sizeof(isprime));
	k=0;
	prime[1]=0;
    for(int i=2;i<N;i++){
        if(isprime[i]){
            prime[k++]=i;
            for(int j=2;i*j<N;j++)
                isprime[i*j]=0;
        }
    }
}//筛法 

void solve(ll n){
    for(int i=0;i<k&&prime[i]*prime[i]<=n;i++){
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

//inline ll gcd(ll a,ll b)
//{
//    return (a%b==0)?b:gcd(b,a%b);
//}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	Prime();
    cin>>n;
    ll GCD=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!flag) solve(a[i]);
        if(GCD==0) GCD=a[i];
        else GCD=__gcd(GCD,a[i]);
    }
    if(!flag) cout<<"pairwise coprime"<<endl;
    else if(flag&&GCD==1) cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
	return 0;
} 