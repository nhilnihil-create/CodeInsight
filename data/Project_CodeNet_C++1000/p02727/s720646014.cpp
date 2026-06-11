#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int X,Y,A,B,C;cin >> X >> Y >> A >> B >> C;
  vector<ll> P(A);
  vector<ll> Q(B);
  vector<ll> R(C);
  for(int i=0;i<A;i++){
    cin >> P[i];
  }
  for(int i=0;i<B;i++){
    cin >> Q[i];
  }
  for(int i=0;i<C;i++){
    cin >> R[i];
  }
  sort(P.begin(),P.end());
  reverse(P.begin(),P.end());
  sort(Q.begin(),Q.end());
  reverse(Q.begin(),Q.end());
  for(int i=0;i<X;i++){
    R.push_back(P[i]);
  }
  for(int i=0;i<Y;i++){
    R.push_back(Q[i]);
  }
  sort(R.begin(),R.end());
  reverse(R.begin(),R.end());
  ll sum = 0;
  for(int i=0;i<X+Y;i++){
    sum += R[i];
  }
  cout << sum << endl;
}