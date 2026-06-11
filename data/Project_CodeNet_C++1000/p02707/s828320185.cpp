#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0)return A;
  else return GCD(B,A%B);
}
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N-1);
  for(int i=0;i<N-1;i++){
    cin>>A[i];
  }
  
  vector<int> ans(N);
  
  
  for(int i=0;i<N-1;i++){
    ans[A[i]-1]++;
  }
  
  
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
}