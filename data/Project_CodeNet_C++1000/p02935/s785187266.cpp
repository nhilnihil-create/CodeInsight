#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<double>V(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>V[i];
  }
  sort(V.begin(),V.end());
  for(int i=0;i<=N-2;i++){
  
    V[i+1]=(V[i]+V[i+1])/2;
  }
  cout<<V[N-1];
  return 0;
}