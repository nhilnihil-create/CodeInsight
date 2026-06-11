#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,count=0;
  vector<int> p(N);
  cin>>N;
  for(int i=0;i<N;i++) cin>>p[i];
  
  for(int i=0;i<N;i++){
    if(p[i]!=i+1) count++;
  }
  
  if(count==0||count==2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
}
    