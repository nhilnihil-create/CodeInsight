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

pair<int,int> func(int x){
    int a=x%10;
    int b=0;
    while(x){
        b=x;
        x/=10;
    }
    return pair<int,int>(a,b);
}
int main() {
  int N;
  cin>>N;
  map<pair<int,int>,int>Q;
  for(int i=1;i<=N;i++){
      Q[func(i)]++;
  }
  int64_t cnt=0;
  for(int i=1;i<=N;i++){
      pair<int,int>S=func(i);
      pair<int,int>f(S.second,S.first);
      cnt+=Q[f];
  }
  cout<<cnt<<endl;
  return 0;
}