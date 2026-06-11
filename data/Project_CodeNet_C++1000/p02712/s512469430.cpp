#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  ll n, ans=0;
  cin >> n;
  vector<int> a(n);

  rep(i, n){
    if((i+1)%3==0){
      continue;
    }
    else{
      if((i+1)%5==0){
        continue;
      }
      else{
        a[i]=i+1;
      }
    }
  }

  rep(i, n){
    ans+=a[i];
  }

  cout << ans << endl;

  return 0;
}