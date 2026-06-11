#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
int main() {
  int N,ans=0;cin>>N;
  vector<int> vec(N);
  rep(i,N) cin>>vec.at(i);
  
  int num=1;
  for(int i=0;i<N;i++){
    if(vec[i]==num){
      num++;
      continue;
    }
    else ans++;
  }
  
  if(num==1) cout << -1 << endl;
  else cout << ans << endl; 
}