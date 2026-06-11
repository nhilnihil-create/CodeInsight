#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long h;
  cin>>h;
  if(h==1){
      cout<<1;
      return 0;
  }
  long long ans = 1LL << (64-__builtin_clzll(h));
  cout<<ans-1<<"\n";
  return 0;
}

