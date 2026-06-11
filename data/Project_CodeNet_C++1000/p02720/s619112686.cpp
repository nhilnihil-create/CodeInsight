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
int keta(int x){
  int cnt=0;
  while(x){
    cnt++;
    x/=10;
  }
  return cnt;
}
int main() {
  int K;
  cin>>K;
  vector<int64_t>start;
  for(int i=1;i<=9;i++){
    start.push_back(i);
  }
  int n=K;
  while(n--){
    if(K<=start.size()){
      cout<<start[K-1]<<endl;
      return 0;
    }
    K-=start.size();
    vector<int64_t>table;
    table.clear();
    swap(table,start);
    for(int64_t x:table){
      for(int i=-1;i<=1;i++){
        int64_t a=x%10+i;
        if(a<0||a>9){continue;}
        int64_t d=10*x+a;
        start.push_back(d);
      }
    }
  }
  return 0;
}