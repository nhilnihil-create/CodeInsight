#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int K;
  cin>>N>>K;
  int P[N];
  int count =0;
 if(N>=1&&K>=1&&N<=100000&&K<=500){
  for(int i=0;i<N;i++){
      cin>>P[i];
      if(P[i]>=K&&P[i]>=1&&P[i]<=500){
          count++;
      }
  }
  cout<<count;
 }
   return 0;
   
}