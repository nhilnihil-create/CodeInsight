#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  int sum=0;
  int ans =0;
  for(int i=0;i<N-1;i++){
    if(A.at(i)>=A.at(i+1)){
      sum++;
    }else if(sum>ans){
      ans =sum;
      sum=0;
    }else{
      sum=0;
    }
  }
 if(sum>ans){
   cout<<sum<<endl;
 }else{
   cout<<ans<<endl;
 }
}