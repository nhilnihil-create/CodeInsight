#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K,Q;
  cin>>N>>K>>Q;
  vector<int>A(N,K-Q);
  for(int i=0;i<Q;i++){
    int a;
    cin>>a;
    a--;
    A.at(a)++;
  }
  for(int i=0;i<N;i++){
    if(A.at(i)<=0){
      cout<<"No"<<endl;
    }
    else{
      cout<<"Yes"<<endl;
    }
  }
}
  