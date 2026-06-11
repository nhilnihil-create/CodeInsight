#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  map<int,int> A;
  for(int i=1; i<=N; i++){
    int x;
    cin>>x;
    A[x]=i;
  }
  for(int i=1; i<=N; i++){
    cout<<A[i]<<" ";
    if(i==N){
      cout<<endl;
    }
  }
}