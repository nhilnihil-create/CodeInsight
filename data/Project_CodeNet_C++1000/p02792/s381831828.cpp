#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<vector<int>>A(10,vector<int>(10));
  for(int i=1;i<=N;i++){
    string S=to_string(i);
    A[S.at(0)-48][S.at(S.size()-1)-48]++;
  }
  long long ans=0;
  for(int i=1;i<10;i++)for(int j=1;j<10;j++)ans+=A[i][j]*A[j][i];
  cout<<ans<<endl;
}