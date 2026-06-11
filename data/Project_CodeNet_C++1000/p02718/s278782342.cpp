#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll=long long;

int main(){
    ll N,M;
  ll sum=0;
  ll counter=0;
  cin >> N >> M;
  vector<ll> A(N);
  for(ll i=0;i<A.size();i++){
    cin >> A[i];
  	sum+=A[i];
  }
  
  for(ll i=0;i<A.size();i++){
    double tmp= (double)sum/(double)(4*M);
    if(A[i]>=tmp )counter++;
  }
  if(counter>=M){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}