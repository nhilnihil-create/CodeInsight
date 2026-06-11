#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,j=0,k=0;
  cin>>N>>M;
  vector<bool> A(N,true);
  vector<int> B(N,0);
  for(int i=0;i<M;i++){
    int p;
    string S;
    cin>>p>>S;
    if(S=="AC"){
      if(A[p-1]){
        k++;
        j+=B[p-1];
        A[p-1]=false;
      }
    }else{
      B[p-1]++;
    }
  }
  cout<<k<<' '<<j<<endl;
}