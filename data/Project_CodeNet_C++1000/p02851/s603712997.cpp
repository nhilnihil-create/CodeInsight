#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,k;cin>>n>>k;
  vector<int> a(n+1,0);
  rep1(i,n)cin>>a[i];
  vector<int> sum(n+1,0);
  rep1(i,n){
    sum[i]=sum[i-1]+a[i];
  }
  map<int,int> memo;
  if(k>n){
    rep(i,n+1){
    int buf=(sum[i]-i+n*k)%k;
    int hoge=memo[buf];
    memo[buf]+=1;
    }
    int res=0;
    auto it=memo.begin();
    while(it!=memo.end()){
    int buf=it->second;
    res+=buf*(buf-1)/2;
    //printf("%lld %lld\n",it->first,it->second);
    ++it;
    }
    cout<<res<<"\n";
  }
  else{
    rep(i,k){
    int buf=(sum[i]-i+n*k)%k;
    int hoge=memo[buf];
    memo[buf]+=1;
    }
    int res=0;
    auto it=memo.begin();
    while(it!=memo.end()){
    int buf=it->second;
    res+=buf*(buf-1)/2;
    //printf("%lld %lld\n",it->first,it->second);
    ++it;
    }
    for(int i=k;i<=n;i++){
      int buf=sum[i-k]-(i-k)+n*k;
      buf%=k;
      memo[buf]--;
      buf=sum[i]-i+k*n;
      buf%=k;
      res+=memo[buf];
      memo[buf]+=1;
    }
    cout<<res<<"\n";
  }
  return 0;
}
