#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;cin>>N>>K;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  vector<int> B(N,0);

  int count=0;
 // int all;
  while(count<K){
    //all=0;
    for(int i=0;i<N;i++){
      int l=max(0,i-A[i]);
      int r=min(N-1,i+A[i]);
      B.at(l)++;
      if(r+1<N) B.at(r+1)--;
    }
    for(int i=1;i<N;i++) B.at(i)+=B.at(i-1);
    
    for(int i=0;i<N;i++){
      A.at(i)=B.at(i);
      B.at(i)=0;
    }
	bool can=false;
    for(int j=0;j<N;j++){
      if(A.at(j)!=N) can=true;
      //goto Fin;
    }
    if(!can) break;
    count++;
  }
//Fin:
  for(int i=0;i<N;i++) cout<<A.at(i)<<" ";
}
