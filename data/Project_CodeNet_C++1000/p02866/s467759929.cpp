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
  int N;
  cin>>N;
  vector<int>D(N);
  map<int,int>k;
  for(int i=0;i<N;i++){
    cin>>D[i];
    k[D[i]]++;
  }
  if(D[0]!=0||k[0]!=1){cout<<0<<endl;}
  else{
    int64_t ans=1;
    for(int i=0;i<N;i++){
      if(D[i]!=0){
        ans*=k[D[i]-1];
        ans%=998244353;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}