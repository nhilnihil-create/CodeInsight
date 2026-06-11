#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> P(N),Q(N);
  rep(i,N)cin>>P[i];
  rep(i,N)cin>>Q[i];
  vector<int> A(N);
  rep(i,N)A[i]=i+1;
  map<vector<int>,int>MP;
  do{
    MP[A]=MP.size();
  }while(next_permutation(begin(A),end(A)));
  
  int ans=abs(MP[P]-MP[Q]);
  cout<<ans<<endl;
  return 0;
}