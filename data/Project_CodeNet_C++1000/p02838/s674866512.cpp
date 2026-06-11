#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
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

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t ans=0;
  for(int s=0;s<60;s++){
    int64_t ONE=0,ZERO=0;
    for(int i=0;i<N;i++){
      if((A[i]>>s)&1){ONE++;}
    }
    ZERO=N-ONE;
    int64_t t=ONE*ZERO;
    t%=mod;
    for(int i=0;i<s;i++){
      t*=2;
      t%=mod;
    }
    ans+=t;
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;  
}