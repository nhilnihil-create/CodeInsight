#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long>> prime_factorize(long long N){
  vector<pair<long long,long long>> A;
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0){
      continue;
    }
    long long ex=0;
    while(N%i==0){
      ex++;
      N/=i;
    }
    A.push_back(make_pair(i,ex));
  }
  if(N!=1){
    A.push_back(make_pair(N,1));
  }
  return A;
}
 
int main(){
  long long N,count=0;
  cin >> N;
  vector<pair<long long,long long>> A=prime_factorize(N);
  for(long long i=0;i<A.size();i++){
    long long B=A.at(i).second;
    long long C=1;
    while(B-C>=0){
      count++;
      B-=C;
      C++;
    }
  }
  cout << count << endl;
}