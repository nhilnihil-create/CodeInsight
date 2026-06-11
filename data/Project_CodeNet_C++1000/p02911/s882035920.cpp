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
  
  int N,K,Q;
  cin>>N>>K>>Q;
  
  vector<int> A(Q);
  for(int i=0;i<Q;i++){
    cin>>A[i];
  }
  
  vector<int> point(N,K-Q);
  
  
  for(int i=0;i<Q;i++){
    point[A[i]-1]++;
  }
 
  
  for(int i=0;i<N;i++){
    if(point[i]>0){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}