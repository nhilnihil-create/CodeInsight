#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<ll> v;
  for(int i=0;i<n;i++){
    ll a=0;
    while(i+a<n && s[i+a]==s[i]){
      a++;
    }
    v.push_back(a);
    i=i+a-1;
  }
  
  if(2*k+1>=v.size())cout << n-1 << endl;
  else{
    ll l=0;//maxをとるスタート地点。このとき、l+1～l+kの向きをそろえることになる。
    ll m=0;//vの中の連続する2k+1個の和のmax
    ll c[v.size()-2*k]={};//vの中の、i番目から連続した2k+1個の和
    for(int i=0;i<2*k+1;i++)c[0]+=v[i];
    for(int i=1;i<v.size()-2*k;i++){
      c[i]=c[i-1]-v[i-1]+v[i+2*k];
    }
    m=c[0];
    for(int i=1;i<v.size()-2*k;i++){
      if(c[i]>m){
        l=i;
        m=c[i];
      }
    }
    m=m-v[l]-v[l+2*k];
    ll p=0;//vの0番目からl番目まで足す
    for(int i=0;i<=l;i++){
      p+=v[i];
    }
    if(s[p]=='R'){
      for(int i=0;i<m;i++){
        s[p+i]='L';
      }
    }
    else{
      for(int i=0;i<m;i++){
        s[p+i]='R';
      }
    }
    /*for(int i=0;i<n;i++){
      cout << s[i] ;
    }
    cout << endl;*/

    ll t=0;
    for(int i=0;i<n;i++){
      if(i==0){
        if(s[i]=='R'&& s[i+1]=='R')t++;
      }
      else if(i==n-1){
        if(s[i]=='L' && s[i-1]=='L')t++;
      }
      else{
        if(s[i]=='R'&& s[i+1]=='R')t++;
        if(s[i]=='L' && s[i-1]=='L')t++;
      }
    }
    cout << t << endl;

  }

}