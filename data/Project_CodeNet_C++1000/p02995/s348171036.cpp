#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int64_t func(int64_t x,int64_t y){
  return y-y/x;
}
int main() {
  int64_t A,B,C,D;
  cin>>A>>B>>C>>D;
  int64_t l=C*D/__gcd(C,D);
  cout<<func(C,B)-func(C,A-1)+func(D,B)-func(D,A-1)-(func(l,B)-func(l,A-1))<<endl;
  return 0;
}