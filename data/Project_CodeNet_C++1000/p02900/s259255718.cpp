#include<bits/stdc++.h>
using namespace std;

long long gcd(long long A,long long B){
  if(B==0){
    return A;
  }
  return gcd(B,A%B);
}

vector<pair<long long,long long>> prime_factorize(long long A){
  vector<pair<long long,long long>> res;
  for(long long i=2;i*i<=A;i++){
    if(A%i!=0){
      continue;
    }
    long long ex=0;
    while(A%i==0){
      ex++;
      A/=i;
    }
    res.push_back(make_pair(i,ex));
  }
  if(A!=1){
    res.push_back(make_pair(A,1));
  }
  return res;
}
    
int main(){
  long long A,B;
  cin >> A >> B;
  long long C=gcd(A,B);
  vector<pair<long long,long long>> D=prime_factorize(C);
  cout << D.size()+1 << endl;
} 