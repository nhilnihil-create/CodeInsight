#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll a,b,c;
  cin >>a>>b>>c;
  vector<ll> vec1(a);
  vector<ll> vec2(b);
  ll t=0;
  for(ll i=0;i<a;i++){
    cin >>vec1[i];
  }
  for(ll j=0;j<b;j++){
    cin >> vec2[j];
    t+=vec2[j];
  }
  ll j=b;
  ll ans=0;
  for(ll i=0;i<=a+1;i++){
    while(j>0 && t>c){
      j--;
      t-=vec2[j];
    }
    if(t >c){
      break;
    }
    ans=max(ans,i+j);
    if(i==a){
      break;
    }
    t+=vec1[i];
  }
  cout << ans <<endl;
}

  