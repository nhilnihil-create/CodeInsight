#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int main() {
  int X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  vector<int>p(A),q(B),r(C);
  for(int i=0;i<A;i++){cin>>p[i];}
  for(int i=0;i<B;i++){cin>>q[i];}
  for(int i=0;i<C;i++){cin>>r[i];}
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  vector<int>d;
  for(int i=0;i<X;i++){d.push_back(p[i]);}
  for(int i=0;i<Y;i++){d.push_back(q[i]);}
  for(int i=0;i<C;i++){d.push_back(r[i]);}
  sort(d.rbegin(),d.rend());
  int64_t ans=0;
  for(int i=0;i<X+Y;i++){ans+=d[i];}
  cout<<ans<<endl;
  return 0;
}