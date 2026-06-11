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

const int INF=1001001001;

int main() {
  double A,B,H,M;
  cin>>A>>B>>H>>M;
  double h=(H/12+M/60/12)*2*M_PI;
  double m=M/60*2*M_PI;
  double bx=B*cos(m),by=B*sin(m);
  double ax=A*cos(h),ay=A*sin(h);
  double dx=ax-bx,dy=ay-by;
  cout<<fixed<<setprecision(10)<<sqrt(dx*dx+dy*dy)<<endl;
  return 0;
}