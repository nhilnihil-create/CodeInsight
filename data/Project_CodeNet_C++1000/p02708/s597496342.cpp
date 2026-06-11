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
  int64_t N,K;
  cin>>N>>K;
  int64_t ans=0;
  for(int64_t i=K;i<=N+1;i++){
    int64_t MIN=(i-1)*(i)/2;
    int64_t MAX=(N+N-i+1)*(i)/2;
    ans+=(MAX-MIN+1);
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}