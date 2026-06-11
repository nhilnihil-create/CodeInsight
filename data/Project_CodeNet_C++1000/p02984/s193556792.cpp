#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  long long count1=0,count2=0;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    count1+=A[i];
    if(i%2==1)count2+=A[i];
  }
  vector<long long>B(N);
  B[0]=count1-2*count2;
  cout<<B[0]<<" ";
  for(int i=1;i<N;i++){B[i]=(A[i-1]-B[i]/2)*2-B[i-1];cout<<B[i]<<(i!=N-1? " ":"");}
  cout<<"\n";
}