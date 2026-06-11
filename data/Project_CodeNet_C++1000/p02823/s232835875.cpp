#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, A, B;

ll f1(ll A, ll B) {
  ll ret = A-1;
  A -= ret;
  B -= ret;
  if(A%2 != B%2) {
    --B; ++ret;
  }
  return ret + (B-A)/2;
}

ll f2(ll A, ll B) {
  ll ret = N-B;
  A += ret;
  B += ret;
  if(A%2 != B%2) {
    ++A; ++ret;
  }
  return ret + (B-A)/2;
}

int main() {
  cin>>N>>A>>B;
  
  // meet at 1 / N
  ll ret = min(B-1, N-A);
  
  // head towards each other
  if(B%2 == A%2) {
    ret = min(ret, (B-A)/2);
  }
  // A go to 1 then head towards B
  ret = min(ret, f1(A,B));
  
  // B go to N then head towards A
  ret = min(ret, f2(A,B));
  
  cout<<ret<<"\n";
  return 0;
}