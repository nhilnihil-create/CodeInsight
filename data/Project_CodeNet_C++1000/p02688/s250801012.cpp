#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  int n;
  cin>>N>>K;
  vector<vector<int>> A(K,vector<int>(N));
  for(int i=0;i<K;i++){
    cin>>n;
    for(int j=0;j<n;j++){
      cin>>A.at(i).at(j);
    }
  }
  for(int i=0;i<K;i++){
    for(int j=0;j<N;j++){
      if(A.at(i).at(j)=='\0'){
        A.at(i).at(j)=0;
      }
    }
  }
  
  vector<int> B(N);
  for(int i=0;i<N;i++){
    B.at(i)=1;
  }
   for(int i=0;i<K;i++){
    for(int j=0;j<N;j++){
      if(A.at(i).at(j)!=0){
        B.at(A.at(i).at(j)-1)=0;
      }
    }
   }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=B.at(i);
  }
  cout<<sum<<endl;
}