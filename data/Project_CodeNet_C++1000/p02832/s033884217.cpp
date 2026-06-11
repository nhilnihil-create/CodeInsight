#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  int N,ans=0,num=1;
  bool flag=false;
  cin >> N;
  vector<int> a(N);
  rep(i,N) {
    cin >> a[i];
    if(a[i]==1)flag=true;
  }
  
  if(!flag){
    ans = -1;
  }
  else {
    rep(i,N){
      if(a[i]==num) num++;
    }
    ans = N-num+1;
  }
  cout << ans << endl;
  return 0;
}

