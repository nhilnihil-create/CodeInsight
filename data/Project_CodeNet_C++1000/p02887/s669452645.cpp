#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;cin>>N;
  string S;cin>>S;
  
  int ans=1;
  for(int i=0;i<S.size()-1;i++){
    if(S[i]!=S[i+1]) ans++;
  }
  
  cout << ans << endl;
}
