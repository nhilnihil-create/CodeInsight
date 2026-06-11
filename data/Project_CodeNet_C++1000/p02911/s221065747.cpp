#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,Q;
  cin>>N>>K>>Q;
  vector<int> B(N,K);
  vector<bool> ans(N,true);
  for(int i=0; i<Q; i++){
    int A;
    cin>>A;
    B.at(A-1)++;
  }
  for(int i=0; i<N; i++){
    B.at(i)-=Q;
    if(B.at(i)<=0){
      ans.at(i)=false;
    }
  }
  for(int i=0; i<N; i++){
    if(ans.at(i)){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}
     