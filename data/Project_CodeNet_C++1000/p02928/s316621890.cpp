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
  int64_t N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t p=1000000007;
  int64_t sum=0;
  int64_t cnt=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(A[i]>A[j]){cnt++;}
    }
  }
  sum+=(cnt*K%p);
  cnt=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(A[i]>A[j]){cnt++;}
    }
  }
  sum+=cnt%p*(K*(K-1)/2%p);//割り算のMODは途中でMODしてはいけない
  cout<<sum%p<<endl;
  return 0;
}