#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;long K;cin>>N>>K;
  vector<long> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  sort(A.begin(),A.end());
  long left=1;
  long right=1000000000;
  while(left<right){
    long X=(right+left)/2;
    long count=0;
    for(int i=0;i<N;i++){
      count+=A.at(i)/X;
      if(A.at(i)%X==0) count--;
    }
    if(count>K) left=X+1;
    else right=X;
  }
  cout<<right<<endl;
}
    
