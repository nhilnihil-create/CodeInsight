#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<string>S(N);
  for(int i=0;i<N;i++){
    vector<char>C(10);
    string A; cin>>A;
    for(int j=0;j<10;j++)C[j]=A.at(j);
    sort(C.begin(),C.end());
    for(int j=0;j<10;j++)A.at(j)=C[j];
    S[i]=A;
  }
  sort(S.begin(),S.end());
  long long ans=0;
  int count=1;
  for(int i=1;i<N;i++){
    if(S[i]==S[i-1]){ans+=count;count++;}
    else count=1;
  }
  cout<<ans<<endl;
}