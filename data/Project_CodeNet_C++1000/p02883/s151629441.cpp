#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,K; cin>>N>>K;
  vector<long> A(N),F(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  for(int i=0;i<N;i++) cin>>F.at(i);
  sort(A.begin(),A.end());
  sort(F.begin(),F.end());
  reverse(F.begin(),F.end());
  long left=0;
  long right=1000000000000;
  long X;
  long count;
  while(left<right){
    count=0;
    X=(left+right)/2;
    for(int i=0;i<N;i++){
      //long Y=A.at(i)*F.at(i);
      //if(Y>X) count+=Y-X;
      long Y=floor(X/F.at(i));
      if(A.at(i)>Y) count+= A.at(i)-Y;
    }
    if(count<=K) right=X;
    else left=X+1;
  }
  cout<<left<<endl;
}