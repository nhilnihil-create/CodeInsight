#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,Q;
  cin>>N>>K>>Q;
  vector<int> B(Q);
  vector<int> A(N,K-Q);
  for(int i=0;i<Q;i++){
    cin>>B.at(i);
    A.at(B.at(i)-1)++;
  }
  
  for(int i=0;i<N;i++){
    if(A.at(i)>0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}