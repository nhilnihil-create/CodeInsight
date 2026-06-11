#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  int sum=0;
  
  vector<int> W(N);
  for(int i=0;i<N;i++){
    cin>>W[i];
    sum+=W[i];
  }
  
  int ans=100000;
  
  int sum_1=0;
  
  for(int i=0;i<N;i++){
      sum_1+=W[i];
      
    int sum_2=sum-sum_1;
    
    ans=min(abs(sum_1-sum_2),ans);
  }
  cout<<ans<<endl;
}