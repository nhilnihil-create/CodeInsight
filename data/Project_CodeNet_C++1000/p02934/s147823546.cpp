#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  
  double sum=0;
  for(int i=0;i<N;i++){
    sum+=(double)(1.0/A[i]);
  }
  
  cout<<(long double)(1/sum)<<endl;
}