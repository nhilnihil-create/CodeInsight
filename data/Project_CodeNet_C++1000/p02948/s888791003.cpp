#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<pair<int64_t,int64_t>>A(N);
  for(int i=0;i<N;i++){
  int a,b;
    cin>>a>>b;
    if(0<=M-a){
    pair<int64_t,int64_t>p(b,M-a);
    A.at(i)=p;
    }
  }sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int64_t ans=0;
  vector<int>B(M+1);
  for(int i=0;i<=M;i++)
    B.at(i)=i;
  for(int i=0;i<N;i++){
   int a=B.size();
    if(a==0)
      break;
    auto itr=upper_bound(B.begin(),B.end(),A.at(i).second);
    if(itr==B.begin())
      continue;
    else{
    itr--;
      B.erase(itr);
      ans+=A.at(i).first;
    }
      }cout<<ans<<endl;
     return 0;
}
