#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,sum=0;
  cin>>N;
  for(int i=1; i<=N; i++){
    if(!(i%3==0||i%5==0)){
      sum+=i;
    }
  }
  cout<<sum<<endl;
}