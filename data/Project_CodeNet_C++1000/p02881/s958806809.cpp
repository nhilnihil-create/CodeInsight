#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  ll a,ans;
  cin>>a;
  ll b=sqrt(a);
  for(ll i=b;i>0;i--){
    if(a%i==0){
      ans=i+a/i-2;
      cout<<ans;
      return 0;
    }
  }
}