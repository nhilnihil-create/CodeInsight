#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(pair<int,int> &p:A)
    cin>>p.second>>p.first;
  sort(A.begin(),A.end());
  int t=0;
  for(pair<int,int> &p:A){
    t+=p.second;
    if(t>p.first){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}