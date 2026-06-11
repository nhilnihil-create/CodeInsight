#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> W(N);
  for(int i=0;i<N;i++){
    cin>>W[i];
  }
  
  int ans=100000;
  
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=W[i];
  }
  
  for(int i=0;i<N;i++){
    int sum_1=0;
    for(int j=0;j<=i;j++){
      sum_1+=W[j];
      
    int sum_2=sum-sum_1;
    
    ans=min(abs(sum_1-sum_2),ans);
    }
  }
  
  cout<<ans<<endl;
}