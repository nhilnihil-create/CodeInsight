#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<pair<string,int>> PL(N);
  for(int i=0;i<N;i++){
    string s;int t;
    cin>>s>>t;
    PL[i]=make_pair(s,t);
  }
  string X;cin>>X;
  bool neta=false;
  int time=0;
  for(int i=0;i<N;i++){
    if(X==PL[i].first)neta=true;
    else if(neta)time+=PL[i].second;
  }
  cout<<time<<endl;
}