#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string>S(N);
  for(int i=0;i<N;i++)cin>>S[i];
  
  sort(S.begin(),S.end());
  
  int ans;
  for(int i=0;i<N-1;i++){
    if(S[i]!=S[i+1]){
      ans++;
    }
  }
  
  cout<<ans+1<<endl;
}