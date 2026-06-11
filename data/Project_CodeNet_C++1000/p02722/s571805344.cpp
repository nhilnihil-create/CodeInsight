#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=(1<<29);
map<ll,bool> mp;
ll n,ans=0;
vector<ll> x;
void dfs(ll k){
  if(k==1){
    return;
  }
  ll a=n;
  while(a>=k){
    if(a%k==0){
      a=a/k;
    }
    else{
      a=a%k;
    }
  }
  if(a==1){
    mp[k]=true;
    ans++;
  }
}
int main(){
  ll i;
  scanf("%lld\n",&n);
  for(i=1;i*i<=n;i++){
    if(n%i==0){
      x.push_back(i);
      if((n/i)!=i){
        x.push_back(n/i);
      }
    }
  }
  for(i=0;i<x.size();i++){
    dfs(x[i]);
  }
  n--;
  for(i=1;i*i<=n;i++){
    if(n%i==0 && mp[i]==false){
      mp[i]=true;
      ans++;
    }
    if(n%i==0 && mp[n/i]==false){
      mp[i]=true;
      ans++;
    }
  }
  printf("%lld\n",ans-1);
  return 0;
}