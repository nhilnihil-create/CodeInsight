#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K,R,S,P;
  string T;
  cin>>N>>K>>R>>S>>P>>T;
  vector<char> A(K,'a');
  int k=0;
  for(int i=0;i<N;i++){
    if(A[i%K]!=T[i]){
      A[i%K]=T[i];
      if(T[i]=='r')
        k+=P;
      else if(T[i]=='s')
        k+=R;
      else
        k+=S;
    }else
      A[i%K]='a';
  }
  cout<<k<<endl;
}