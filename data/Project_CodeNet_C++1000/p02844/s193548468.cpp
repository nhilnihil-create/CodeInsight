#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; string S; cin>>N>>S;
  vector<bool>A(10,false);
  long long ans=0;
  for(int i=0;i<N-2;i++){
    if(A[S.at(i)-'0'])continue;
    A[S.at(i)-'0']=true;
    vector<bool>B(10,false);
    for(int j=i+1;j<N-1;j++){
      if(B[S.at(j)-'0'])continue;
      B[S.at(j)-'0']=true;
      vector<bool>C(10,false);
      for(int k=j+1;k<N;k++){
        if(C[S.at(k)-'0'])continue;
        C[S.at(k)-'0']=true;
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}