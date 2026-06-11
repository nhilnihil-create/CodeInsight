#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,X,u=0,L[110],count;
  cin>>N>>X;
  for(int i=0;i<N;i++) cin>>L[i];
  for(int i=0;i<N;i++){
    u += L[i];
    if(u<=X) count++;
    else break;
  }
  cout<<count+1<<endl;
}
