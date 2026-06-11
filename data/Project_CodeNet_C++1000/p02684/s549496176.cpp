#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,K,i,k,n,c,cp;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> r;
  vector<int> odr(N+1,-1);
  for(auto &x:A)
    cin >> x;
  n = 1;
  while(odr[n] == -1){
    odr[n] = r.size();
    r.push_back(n);
    n = A[n-1];
  }
  cp = odr[n];
  c = r.size()-cp;
  if (K>=cp){
    K -= cp;
    k = (K % c) + cp;
  }
  else
    k = K;
  cout << r[k] << endl;
  
  return 0;
}