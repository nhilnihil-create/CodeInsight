#include<iostream>
#include<vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  rep(i, N){
    if(A[i] % 2 == 0){
      if((A[i] % 3 != 0) && (A[i] % 5 != 0)){
	cout << "DENIED\n";
	return 0;
      }
    }
  }

  cout << "APPROVED\n";
  
  return 0;
}
