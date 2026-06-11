#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int count=0;
  for(int i=0;i<N;i++){
    S[i];
    if(N%2==0){
      if(S[i]==S[N/2+i]){
        count++;
      }
    }
  }
  if(2*count==N){
    cout<<"Yes"<<endl;
  }
  if(2*count!=N){
    cout<<"No"<<endl;
  }
}