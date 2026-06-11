#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int main(){
  ll h;
  cin>>h;
  ll i=1,ans=0;
  while(i<=h){
    ans+=i;
    i*=2;
  }
  cout<<ans<<endl;
}