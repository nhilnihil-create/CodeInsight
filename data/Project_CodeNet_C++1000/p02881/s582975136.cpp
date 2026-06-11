#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 1e6+5;
int vis[N];
vector<int> prime;
void getprime(){
    rep(i,2,N-5){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int p:prime){
            ll v= (ll)i*p;
            if(v>N-5) break;
            vis[v] = 1;
            if(i%p==0) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    ll n;cin>>n;
    //getprime();
    ll sq = sqrt(n+0.5);
    //cout<<sq<<'\n';
    for(ll i = sq;i>=1;--i){
        if(n%i==0){
            cout<<i-1+(n/i)-1;break;
        }
    }
    
}