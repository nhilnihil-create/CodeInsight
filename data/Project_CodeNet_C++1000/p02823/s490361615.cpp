#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  if(A%2==B%2){cout<<abs(A-B)/2<<endl;}
  else{
    int64_t d=1+A-1+(B-A-1)/2;
    int64_t u=1+N-B+(B-A-1)/2;
    cout<<min(d,u)<<endl;
  }
  return 0;
}