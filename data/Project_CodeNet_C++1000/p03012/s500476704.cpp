#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>W(N);
  for(int i=0;i<N;i++){
    cin>>W.at(i);
  }
  int ans=1e9;
  for(int i=1;i<N;i++){
    int l=0,k=0;
    for(int j=0;j<i;j++){
      l+=W.at(j);
    }
    for(int j=i;j<N;j++){
      k+=W.at(j);
    }
    ans=min(ans,abs(l-k));
  }
  cout<<ans<<endl;
}
    