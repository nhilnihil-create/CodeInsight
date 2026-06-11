#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  long long N;cin>>N;
  
  long long sum=N*(N+1)/2;
  
  for(int i=1;i<=N;i++){
    if(i%3==0||i%5==0){
      sum-=i;
    }
  }
  
  cout<<sum<<endl;
}