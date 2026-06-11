#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<pair<int,int>>A(M);
  if(N%2==0){
  for(int i=0;i<M;i++){
  if(i%2==0){
  int a=(i/2)+1;
    int b=(N+1-a);
    pair<int,int>p(a,b);
    A.at(i)=p;
  }else{
  int a=N/2-(i+1)/2;
    int b=N-a;
    pair<int,int>p(a,b);
    A.at(i)=p;
  }
  
  
  }
  
  }else{
  for(int i=0;i<M;i++){
  int a=i+1;
    int b=N-1-i;
    pair<int,int>p(a,b);
    A.at(i)=p;
  
  }
  }
    for(int i=0;i<M;i++)
    cout<<A.at(i).first<<" "<<A.at(i).second<<endl;
    return 0;
}