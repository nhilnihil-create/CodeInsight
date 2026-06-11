#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,K;cin>>N>>K;
  vector<long> A(N),F(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  for(int i=0;i<N;i++) cin>>F.at(i);
  sort(A.begin(),A.end());
  sort(F.begin(),F.end());
  reverse(F.begin(),F.end());
  long left=0;
  long right=1000000000001;
  while(left<right){
    long count=0;
    long X=(left+right)/2;
    for(int i=0;i<N;i++){
      if(A.at(i)*F.at(i)>X) count+=A.at(i)-X/F.at(i);
    }
    if(count>K) left=X+1;
    else right=X;
  }
  cout<<right<<endl;
}
