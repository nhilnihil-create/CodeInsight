#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<ll> vec(n);
  rep(i,n){
      cin>>vec[i];
  }
  ll ans=0, zan=0;
  rep(i,n-1){
      if(vec[i]>=vec[i+1]) zan++;
      else{
          if(zan>ans) ans= zan;
          zan = 0;
      }
      if(i==n-2){
          if(zan>ans) ans= zan;
      }
  }
    cout<<ans;
    

}
