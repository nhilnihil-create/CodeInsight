#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  ll H;
  cin>>H;
  ll ans=0;
  for(int i=0;H>=1;i++){
    ans+=pow(2,i);
    H/=2;
  }
  cout<<ans<<endl;
}