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
  int K,N;
  cin>>K>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int r,l;
  int MIN=INF;
  for(int i=0;i<N;i++){
    if(i==0){l=A[0]+(K-A[N-1]);}
    else {l=A[i]-A[i-1];}
    if(i==N-1){r=K-A[N-1]+A[0];}
    else{r=A[i+1]-A[i];}
    int m=min(K-r,K-l);
    chmin(MIN,m);
  }
  cout<<MIN<<endl;
  return 0;  
}