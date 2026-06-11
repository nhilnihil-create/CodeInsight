#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  if(A%2==B%2){cout<<(B-A)/2<<endl;}
  else{
    int64_t MIN=min(A-1,N-B);
    cout<<MIN+(B-A-1)/2+1<<endl;
  }
  
  return 0;  
}