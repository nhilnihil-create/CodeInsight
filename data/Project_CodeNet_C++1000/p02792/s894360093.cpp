#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  int ans=0;
  vector<vector<int>> A(10,vector<int>(10));
  for(int i=0;i<=N;i++){
    string S=to_string(i);
    A[S[0]-'0'][S[S.size()-1]-'0']++;
  }
  for(int i=1;i<10;i++)
    for(int j=1;j<10;j++)
      ans+=A[i][j]*A[j][i];
  cout<<ans<<endl;
}