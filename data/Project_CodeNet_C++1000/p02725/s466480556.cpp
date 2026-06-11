#include <iostream>
#include <vector>
#include <string>
using ll=long long;
using namespace std;
int main(){
	ll K;
	ll N;
	cin >> K >> N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){
    cin >> A[i];
  }
  ll res=-1*(1ll<<60);
  for(ll i=0;i<N-1;i++){
  	res=max(A[i+1]-A[i],res);
  }
  res=max(res,K-A[N-1]+A[0]);
  cout << K-res << endl;
  
}