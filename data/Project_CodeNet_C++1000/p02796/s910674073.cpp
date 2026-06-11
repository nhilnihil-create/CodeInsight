#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(pair<int,int> &p:A){
    int a,b;
    cin>>a>>b;
    p.first=a+b;
    p.second=a-b;
  }
  sort(A.begin(),A.end());
  int ans=0,n=-10000000000;
  for(int i=0;i<N;i++){
    if(A[i].second>=n){
      ans++;
      n=A[i].first;
    }
  }
  cout<<ans<<endl;
}