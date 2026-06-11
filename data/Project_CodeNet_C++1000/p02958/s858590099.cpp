#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> P(N);
  rep(i,N)cin>>P[i];
  int num=0;
  string ans="YES";
  rep(i,N){
    if(P[i]!=i+1)num++;
    if(num>=3)ans="NO";
  }
  cout<<ans<<endl;
}