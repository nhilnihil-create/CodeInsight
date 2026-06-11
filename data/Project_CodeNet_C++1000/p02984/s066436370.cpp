#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
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
const int MOD=1000000007;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int64_t x=0;
  for(int i=0;i<N;i++){
    if(i%2==0){x+=a[i];}
    else{x-=a[i];}
  }
  x/=2;
  vector<int>ans(N);
  ans[0]=x*2;
  for(int i=0;i<N-1;i++){
    ans[i+1]=2*(a[i]-ans[i]/2);
  }
  for(int i=0;i<N;i++){
    cout<<ans[i];
    if(i<N-1){cout<<" ";}
  }cout<<endl;
  return 0;
}