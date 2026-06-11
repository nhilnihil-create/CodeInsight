#include<iostream>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  int c=-1;
  for(int i=1; i<=M; i++){
    if(N-i+1-i<=N/2 && N%2==0){
      c=i;
      break;
    }
    cout<<i<<" "<<N-i+1<<endl;
  }
  if(c!=-1){
    for(int i=c; i<=M; i++){
      cout<<i<<" "<<N-i<<endl;
    }
  }
  cout<<endl;
  return 0;
}
