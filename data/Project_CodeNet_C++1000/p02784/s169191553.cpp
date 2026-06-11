#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,N;
  cin>>H>>N;
  vector<int> A(N);
  int sum=0;
  for(int i=0;i<N;i++){
cin>>A.at(i);
    sum+=A.at(i);
  }
  if(sum-H>=0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}