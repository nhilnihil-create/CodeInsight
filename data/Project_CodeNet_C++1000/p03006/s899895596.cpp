#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<pair<int64_t,int64_t>>A(N);
  for(int i=0;i<N;i++){
  int64_t x,y;
    cin>>x>>y;
    pair<int64_t,int64_t>p(x,y);
    A.at(i)=p;
  }map<pair<int64_t,int64_t>,int>M;
  for(int i=0;i<N-1;i++){
  for(int j=i+1;j<N;j++){
    int64_t x1,y1,x2,y2;
    x1=A.at(i).first-A.at(j).first;
    x2=A.at(j).first-A.at(i).first;
    y1=A.at(i).second-A.at(j).second;
    y2=A.at(j).second-A.at(i).second;
    pair<int64_t,int64_t>p1(x1,y1);
    pair<int64_t,int64_t>p2(x2,y2);
    if(M.count(p1))
      M.at(p1)++;
    else
      M[p1]=1;
    if(M.count(p2))
      M.at(p2)++;
    else
      M[p2]=1;
    
  }
  }int ans=0;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    if(ans<v)
      ans=v;
  }cout<<N-ans<<endl;
   return 0;
}