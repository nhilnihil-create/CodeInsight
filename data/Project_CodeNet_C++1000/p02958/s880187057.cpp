#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>P(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i);
  }
  vector<int>ans(N);
  for(int i=0;i<N;i++){
    ans.at(i)=i+1;
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(ans.at(i)!=P.at(i)){
      count++;
    }
  }
  if(count<=2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
