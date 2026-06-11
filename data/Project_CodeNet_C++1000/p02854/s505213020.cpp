#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >>N;
  long long A[N];
  long long sum=0;
  for (long long i=0;i<N;i++){
    cin>>A[i];
    sum=sum+A[i];
  }
  long long temp=0;
  long long tempB;
  for (long long i=0;i<N;i++){
    temp=temp+A[i];
    if(temp>=sum/2){
      tempB=temp-A[i];
      break;
    }
  }
  cout<<min(abs(sum-temp*2),abs(sum-tempB*2))<<endl;
  return 0;
}
