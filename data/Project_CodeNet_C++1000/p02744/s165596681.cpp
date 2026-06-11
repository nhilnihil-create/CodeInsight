#include <bits/stdc++.h>
#include <stdlib.h>
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

void dfs(char c,int n,string s){
  if(s.size()==n){
    cout<<s<<endl;
  }
  else {
    for(char h='a';h<=(c-'a')+1+'a';h=(h-'a')+1+'a'){
      if(h<(c-'a')+1+'a') dfs(c,n,s+h);
      else dfs(c+1,n,s+h);
    }
  }
}

int main() {
  int n;
  cin>>n;
  dfs('a',n,"a");
  return 0;
}