#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n,k,s;
  cin>>n>>k>>s;
  if(s==1000000000){
    rep(i,n){
      if(i<k) cout<< s <<" ";
      else cout<< s-1 <<" ";
    }
    cout<<endl;
  }else{
    rep(i,n){
      if(i<k) cout<< s <<" ";
      else cout<< s+1 <<" ";
    }
    cout<<endl;
  }
}
