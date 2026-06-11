#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,m;
  cin>>n>>m;
  priority_queue<int> memo;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    memo.push(a);
  }
  for(int i=0;i<m;i++){
    int a=memo.top();
    memo.pop();
    a/=2;
    memo.push(a);
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    int a=memo.top();
    memo.pop();
    ans+=a;
  }
  cout<<ans<<endl;
  return 0;
}
