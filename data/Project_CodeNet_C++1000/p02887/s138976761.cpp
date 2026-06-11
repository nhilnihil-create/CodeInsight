#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin>>N>>S;
  
  int ans=1;
  for(int i=0; i<N-1; i++){
    if(S.at(i)!=S.at(i+1)){
      ans++;
    }
  }
  cout<<ans<<endl;
}