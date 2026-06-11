#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> B(N-1);
  for(int i=0; i<N-1; i++){
    cin>>B.at(i);
  }
  int a=0,sum=B.at(N-2);
  if(N==2){
    cout<<B.at(0)*2<<endl;
    return 0;
  }
  else{
    for(int i=N-3; i>=0; i--){
      a=min(B.at(i),B.at(i+1));
      sum+=a;
      if(i==0){
        if(B.at(i)>B.at(i+1)){
          sum+=B.at(i);
        }
        else{
          sum+=a;
        }
      }
    }
  }
  cout<<sum<<endl;
}
  