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
    A[i]--;
  }
  
  vector<bool>ok(N+1,false);
  vector<int>tab(N+1);
  int c=0;
  int a=0;
  int r=0;
  for(int i=0;i<N;i++){
    c=A[c];
    if(ok[c]){a=i-tab[c];r=tab[c];}
    ok[c]=true;
    tab[c]=i;
  }
  if(N<K){K=(K-r)%a+r;}
  c=0;
  int cnt=0;
  for(int i=0;i<=2*N;i++){
    cnt++;
    c=A[c];
    if(cnt==K){cout<<c+1<<endl;return 0;}
  }
  return 0;
}