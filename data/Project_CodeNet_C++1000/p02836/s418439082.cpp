#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int n = S.size();
  
  int ans=0;
  
  for(int i=0; i<(n/2); i++){
    if(S.at(i)!=S.at(n-1-i)){
      ans++;
    }
  }
  cout<<ans<<endl;
}