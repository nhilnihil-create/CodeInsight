#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
 vector<int> B(N-1);
  for(int i=0;i<N-1;i++){
    cin>>B.at(i);
  }
  int sum=0;
  for(int i=0;i<N-1;i++){
    if(i==0){
      sum+=B.at(0);
    }else if(B.at(i)<=B.at(i-1)){
      sum+=B.at(i);
    }else{
      sum+=B.at(i-1);
    }
  }
  sum+=B.at(N-2);
  cout<<sum<<endl;
}