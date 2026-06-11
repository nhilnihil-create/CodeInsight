#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int64_t n;
  cin >> n;
  if(n==1){
    cout << 0;
    return 0;
  }
  vector<int> v(100000);
  ll p=0,q=0;
  ll i;
  bool is;
  ll cp=n;
  for(i=2;i*i<=n;i++){
    is=false;
    while(cp%i==0){
      v.at(p)++;
      cp/=i;
      is=true;
    }
    if(is){
      p++;
    }
  }
  ll ans=0;
  for(i=0;i<100000;i++){
    q=1;
    while(v.at(i)-q>=0){
      ans++;
      v.at(i)-=q;
      q++;
    }
  }
  if(ans==0){
    cout << 1;
    return 0;
  }
  if(cp!=1){
    ans++;
  }
  cout << ans;
}
   