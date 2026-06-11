#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  string S,S1,S2,ans="Yes";
  cin >> S;
  bool flag=1;
  int N=S.size(),n=(N-1)/2;
  rep(i,N/2){
    if(S[i]!=S[N-1-i]){
      flag=0; 
    }
  }
  if(flag){
  S1=S.substr(0,n);
  S2=S.substr(n+1,n);
  rep(i,n/2){
    if(S1[i]!=S1[n-1-i]){
      flag=0; 
    }
    if(S2[i]!=S2[n-1-i]){
      flag=0; 
    }
  }
  }

  
  if(!flag) ans="No";
  cout << ans << endl;
  return 0;
}
