#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a,ll b){
  return b/__gcd(a,b)*a;
}

int main(){
  ll N,M,i;
  ll count;
  ll A[222222];
  bool check = true;
  cin >> N >> M;
  for(i=0;i<=N-1;i++){
    cin >> A[i];
    A[i] /= 2;
    }
  ll a = 0;
  while(A[0] % 2 == 0){
    a++;
    A[0] /= 2;
    }
  ll cm = A[0];
  for(i=1;i<=N-1;i++){
    count = 0;
    while(A[i] % 2 == 0){
      count++;
      A[i] /= 2;
    }
    cm = lcm(cm,A[i]);
    if(cm > M) check = false;
    if(count != a) check = false;
  }
  ll x = 1;
  x = x << a;
  x *= cm;
  ll y = 2*x;
  if(check) cout << M / x - M / y;  
  else cout << 0 << endl;
}