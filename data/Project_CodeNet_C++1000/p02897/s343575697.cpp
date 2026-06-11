#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;cin>>N;
  
  double count=0;
  
  for(int i=1;i<=N;i++){
    if(i%2==1){
      count++;
    }
  }
  
  double ans=count/N;
  
  printf("%.8f",ans);
}