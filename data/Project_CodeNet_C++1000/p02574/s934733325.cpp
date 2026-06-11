#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int gcd(int x, int y){
  if(x==0) return y;
  else return gcd(y%x,x);
}
int main(){
  int N;
  cin>>N;
  int A[1000000];
  int M=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    M=max(M,A[i]);
  }
  int judge[1000001];
  for(int i=1;i<=M;i++) judge[i]=0;
  for(int i=2;i<=M;i++){
    if(judge[i]==0){
      for(int j=i;j<=M;j+=i){
        if(judge[j]==0) judge[j]=i;
      }
    }
  }
  int set=0;
  int pnum[1000001];
  for(int i=1;i<=M;i++) pnum[i]=0;
  for(int i=0;i<N;i++){
    int a=A[i];
    while(a!=1){
      int n=judge[a];
      while(a%n==0) a/=n;
      pnum[n]++;
    }
  }
  for(int i=1;i<=M;i++){
    if(pnum[i]>1){
      set=1; break;
    }
  }
  if(set==0) cout<<"pairwise coprime"<<endl;
  else{
    int g=A[0];
    for(int i=1;i<N;i++){
      g=gcd(g,A[i]);
    }
    if(g==1) cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
  }
  
  return 0;
}