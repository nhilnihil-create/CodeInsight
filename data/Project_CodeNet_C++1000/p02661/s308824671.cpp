#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  double A[N];
  double B[N];
  int ans=0;
  double midA,midB;
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }
  sort(A,A+N);
  sort(B,B+N);
  if(N%2==0){
    midA=(A[N/2]+A[(N/2)-1])/2;
    midB=(B[N/2]+B[(N/2)-1])/2;
    ans=(int)((midB-midA)/(0.5)+1);
  }
  if(N%2==1){
    midA=A[(N-1)/2];
    midB=B[(N-1)/2];
    ans=(int)(midB-midA+1);
  }  
  cout<<ans<<endl;
  //cout<<midA<<" "<<midB<<endl;
  return 0;
  }