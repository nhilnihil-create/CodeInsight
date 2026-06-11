#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  bool ans=true;
  for(int i=0; i<N-1; i++){
    if(a.at(i)==a.at(i+1)){
      ans=false;
      break;
    }
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}