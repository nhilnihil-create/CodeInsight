#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string>s(N);
  vector<int>t(N);
  string X;
   for(int i=0;i<N;i++){
    cin>>s.at(i)>>t.at(i);
   }
  cin>>X;
  
  int ans=0;
  for(int i=0;i<N;i++){
    if(s.at(i)==X){
      for(int j=i+1;j<N;j++){
        ans+=t.at(j);
      }
      break;
    }
  }
  cout<<ans<<endl;
}
        