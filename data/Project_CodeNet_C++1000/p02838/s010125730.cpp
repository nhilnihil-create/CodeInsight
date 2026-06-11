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

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t ans=0;
  int64_t two=1;
  for(int i=0;i<60;i++){
    int64_t cnt0=0,cnt1=0;
    for(int j=0;j<N;j++){
      if(A[j]>>i&1){cnt1++;}
      else{cnt0++;}
    }
    int64_t a=(cnt1*cnt0)%1000000007*two;
    ans=(ans+a)%1000000007;
    two=two*2%1000000007;
  }
  cout<<ans<<endl;
  return 0;
}