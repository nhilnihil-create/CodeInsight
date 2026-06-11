#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int N;
  cin>>N;
  
  vector<int> B(N-1);
  for(int i=0;i<N-1;i++){
    cin>>B[i];
  }
  
  
  int sum=B[0]+B[N-2];
  for(int i=0;i<N-2;i++){
    sum+=min(B[i],B[i+1]);
  }
  
  
  cout<<sum<<endl;
}