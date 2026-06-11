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
  int N;
  cin>>N;
  vector<pair<int64_t,int64_t>>p(N);
  for(int i=0;i<N;i++){
    int64_t x,y;
    cin>>x>>y;
    p[i]=make_pair(x+y,x-y);
  }
  sort(p.begin(),p.end());
  int cnt=1;
  int64_t B=p[0].first;
  for(int i=0;i<N;i++){
    if(i>0&&p[i].second>=B){cnt++;B=p[i].first;}
  }
  cout<<cnt<<endl;
  return 0;
}