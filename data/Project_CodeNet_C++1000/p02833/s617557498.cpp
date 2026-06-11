#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  ll n;
  cin>>n;
  ll ans=0;
  if(n%2==1) ans=0;
  else{
    ll div=5;
    while(n/div!=0){
      ans+=n/div/2;
      div*=5;
    }
  }
  cout<<ans<<endl;
}
