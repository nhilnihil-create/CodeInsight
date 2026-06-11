#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  map<int,int> A;
  uint32_t B=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a]++;
    B^=(uint32_t)a;
  }
  if(A.size()==3){
    int j=-1;
    uint32_t B=0;
    for(pair<int,int> p:A){
      if(j==-1)j=p.second;
      else if(j!=p.second){
        puts("No");
        return 0;
      }
      B^=(uint32_t)p.first;
    }
    if(B==0)puts("Yes");
    else puts("No");
  }else if(A.size()==2){
    if(A[0]==N/3)puts("Yes");
    else puts("No");
  }else if(A.size()==1){
    if(A.count(0))puts("Yes");
    else puts("No");
  }else puts("No");
}