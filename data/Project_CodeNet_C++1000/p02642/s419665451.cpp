#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(N);
  vector<int> B(1000010,0);
  set<int> S;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    B.at(A.at(i))++;
    S.insert(A.at(i));
  }
  vector<bool> flag(1000010,false);
  for(int i:S){
    for(int j=2;j<1000001;j++){
      if(i*j>=1000001) break;
      flag.at(i*j)=true;
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(B.at(A.at(i))==1 && !flag.at(A.at(i))) ans++;
  }
  cout<<ans<<"\n";
}
