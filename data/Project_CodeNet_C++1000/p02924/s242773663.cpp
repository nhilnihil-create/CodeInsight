#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N;
 cin>>N;
 int64_t ans=0;
 for(int i=1;i<N;i++){
  ans+=i;
 }
 cout<<ans<<endl;
 return 0;
}
