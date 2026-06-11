#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  vector<int>p(A),q(B),r(C);
  vector<int>ans;
  for(int i=0;i<A;i++){cin>>p[i];}
  for(int i=0;i<B;i++){cin>>q[i];}
  for(int i=0;i<C;i++){cin>>r[i];ans.push_back(r[i]);}
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  for(int i=0;i<X;i++){ans.push_back(p[i]);}
  for(int i=0;i<Y;i++){ans.push_back(q[i]);}
  sort(ans.rbegin(),ans.rend());
  int64_t sum=0;
  for(int i=0;i<X+Y;i++){
    sum+=ans[i];
  }
  cout<<sum<<endl;
  return 0;  
}