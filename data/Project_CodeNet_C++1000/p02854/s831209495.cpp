#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long int N; cin >>N;
  long double sum=0;
  vector<long long int>A(N);
  vector<long long int>B(N);
  for(long long int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=A.at(i);
    if(i==0){
      B.at(i)=A.at(i);
    }else{
      B.at(i)=B.at(i-1)+A.at(i);
    }
  }
  long long int k=0;
  for(long long int i=0;i<N;i++){
    if(2*B.at(i)>=sum){
      k=i;
      break;
    }
  }  
  if(2*B.at(k)==sum){
    cout<<0<<endl;
  }else{
    cout<<fixed<<setprecision(0)<<min(abs(sum-2*B.at(k)),abs(sum-2*B.at(k-1)))<<endl;
  }
  return 0;
}