//Code Author: S.M. Istiak Ahmed
#include<bits/stdc++.h>
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
using namespace std;

struct mc{
    vector<ll> v;
    stack<ll> g,s;
};
struct st{
    int val,l,r;
};
ll getMax(mc &x){
  return x.v[x.g.top()];
}
ll getMin(mc &x){
  return x.v[x.s.top()];
}
ll top(mc &x){
  return x.v.back();
}
bool isEmpty(mc &x){
  if(x.v.size()) return 0;
  return 1;
}
void pushVal(mc &x,ll val){
  ll sz=x.v.size();
  x.v.push_back(val);
  if(x.g.empty()) x.g.push(sz);
  else if(val>=x.v[x.g.top()]) x.g.push(sz);
  if(x.s.empty()) x.s.push(sz);
  else if(val<=x.v[x.s.top()]) x.s.push(sz);
}
void popVal(mc &x){
  ll sz=x.v.size();
  if(!sz){
    return;
  }
  if(sz-1==x.g.top()) x.g.pop();
  if(sz-1==x.s.top()) x.s.pop();
  x.v.pop_back();
}

int power(ll x,ll y,int p){
    int res=1;
    //x=x%p;
    if(x==0) return 0;
    while(y>0){
        if(y&1)
            res=(res*x);
        y=y>>1;
        x=(x*x);
    }
    return res;
}
bool isPrime(int n){
    if(n<=1)
        return 0;
    if(n<=3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(int i=5; i*i<=n; i+=6){
        if(n%i==0 || n%(i+2)==0){
            return 0;
        }
    }
    return 1;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll x,k,d,ans;
  cin>>x>>k>>d;
  x=abs(x);
  if(x/d<=k){
    ans=x%d;
    if((k-(x/d))&1) ans-=d,ans=abs(ans);
  }else ans=x-(k*d);
  cout<<ans;
  return 0;
}
