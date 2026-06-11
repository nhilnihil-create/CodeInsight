#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  long long ans=0;
  cin>>N;
  vector<int>S(N);
  for(int i=0;i<N;i++){
    cin>>S[i];
  }
  for(int i=0;i<N-1;i++){
    if(S[i]>S[i+1]){
      ans+=S[i]-S[i+1];
      S[i+1]=S[i];
    }
  }
  cout<<ans<<endl;
}