#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

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
  vector<int>a(N+1);
  for(int i=1;i<=N;i++){
    cin>>a[i];
  }
  vector<int>d(N+1);
  int M=0;
  for(int i=N;i>=1;i--){
    int sum=0;
    for(int j=2;j<=N/i;j++){
       if(i*j<=N){sum+=d[i*j];}
    }
    if(sum%2!=a[i]){M++;d[i]=1;}
  }

  cout<<M<<endl;
  for(int i=1;i<=N;i++){
    if(d[i]==1){
      cout<<i;
      if(i<N){cout<<" ";}
    }
  }cout<<endl;
  return 0;
}