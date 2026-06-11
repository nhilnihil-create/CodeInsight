#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
ll mod=pow(10,9)+7;
ll K,ans;
mat G;

struct Permutation{
    vec n,n_rev;

    Permutation(int N){
        n.resize(N+1);
        n_rev.resize(N+1);
        n[0]=1;n_rev[1]=1;
        for(int i=1;i<=N;i++){
            n[i]=((ll)i*n[i-1])%mod;
        }
        for(int i=2;i<=N;i++){
            n_rev[i]=matpow(n[i],mod-2);
        }
    }

    //累乗(aのk乗)
    ll matpow(ll a,int k){
        ll dp=1,mt=a;
        while(k>0){
            if(k & 1)dp=(dp*mt)%mod;
            mt=(mt*mt)%mod;
            k/=2;
        }
        return dp;
    }

    ll perm(int N,int r){  
        if(N<r)return 0;
        if(N==r)return n[N];
        return (n[N]*n_rev[N-r])%mod;
    }
};

Permutation Perm(100000);
void DFS(int start,int s,int p){
    int r=G[s].size()-1;
    if(s==start){
        ans=(ans*Perm.perm(K-1,r+1))%mod;       
    }
    else{
        ans=(ans*Perm.perm(K-2,r))%mod;
    }
    for(int t:G[s]){
        if(t==p)continue;
        DFS(start,t,s);
    }
}

int main(){
    int N;cin>>N>>K;
    if(K==1){
        if(N==1)cout<<1<<endl;
        else    cout<<0<<endl;
        return 0;
    }
    G.resize(N+1);
    int a,b;
    for(int i=1;i<N;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans=K;
    DFS(1,1,0);
    cout<<ans<<endl;
    return 0;
}