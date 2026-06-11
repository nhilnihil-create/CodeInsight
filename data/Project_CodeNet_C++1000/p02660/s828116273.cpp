#include <bits/stdc++.h>
using namespace std; 

using A=vector<pair<long long,long long>>;

A prime_factorize(long long N){
  A res;
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0){
      continue;
    }
    long long ex=0;
    while(N%i==0){
      ex++;
      N/=i;
    }
    res.push_back(make_pair(i,ex));
  }
  if(N!=1){
    res.push_back(make_pair(N,1));
  }
  return res;
}
    
int main(){
  long long N,count=0;
  cin >> N;
  A res=prime_factorize(N);
  for(int i=0;i<res.size();i++){
    long long B=res.at(i).second;
    int j=1;
    while(B-j>=0){
      count++;
      B-=j;
      j++;
    }
  }
  cout << count << endl;
}