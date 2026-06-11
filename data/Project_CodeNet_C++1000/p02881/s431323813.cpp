#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
  ll a;
  cin>>a;
  ll ans=a-1;
  for(int i=2;i<=sqrt(a)+1;i++){
    if(a%i==0){
      ans=a/i+i-2;
    }
  }
  cout<<ans<<endl;
}