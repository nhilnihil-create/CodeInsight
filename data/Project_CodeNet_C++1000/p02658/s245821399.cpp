#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N,i;
  bool isZero=false, isOver=false;
  cin>>N;
  vector<ll> A(N);
  ll ans = 1, MAX=1e18;
  for (i=0;i<N;i++) {
    cin>>A[i];
    if (!isZero) {
      if (A[i]==0) isZero = true;
      else if (!isOver && A[i] <= MAX/ans) ans*=A[i];
      else isOver = true;
    }
  }
  cout<<(isZero ? 0 : (isOver ? -1 : ans))<<endl;
  return 0;
}
