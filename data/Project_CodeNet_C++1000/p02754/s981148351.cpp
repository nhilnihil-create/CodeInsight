#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,A,B,count=0;
  cin>>N>>A>>B;
  count+=N/(A+B)*A;
  if(N%(A+B)<=A){
    count+=N%(A+B);
  }
  else{
    count+=A;
  }
  cout<<count<<endl;
}