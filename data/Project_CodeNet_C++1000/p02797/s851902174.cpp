#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  ll n,k,s;
  cin>>n>>k>>s;
  ll t;
  if (s<1e9){
    t=s+1;
  }else{
    t=s-1;
  }
  
  rep(i,n){
    if(i<k){
      cout<<s<<" ";
    }else{
    	cout<<t<<" ";
    }
  }

}
