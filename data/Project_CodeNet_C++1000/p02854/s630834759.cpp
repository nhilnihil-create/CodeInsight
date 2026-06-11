#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(N+1);
  B.at(0)=0;
  for(int i=1;i<=N;i++)
    B.at(i)=B.at(i-1)+A.at(i-1);
  int64_t a=B.at(N)/2;
  auto itr=lower_bound(B.begin(),B.end(),a);
  int k=distance(B.begin(),itr);
  int64_t ans=max(B.at(k-1),B.at(N)-B.at(k));
  ans=B.at(N)-2*ans;
  cout<<ans<<endl;
  
    return 0;
}
