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
  vector<int>a(N);
  map<int,int>k;
  for(int i=0;i<N;i++){
    cin>>a[i];
    k[a[i]]++;
  }
  bool ans=false;
  if(k.size()==1&&k[0]==N){ans=true;}
  else if(k.size()==2&&N%3==0&&k[0]==N/3){ans=true;}
  else if(k.size()==3&&N%3==0) {
    bool ok=true;
    int start=0;
    for(auto p:k){
      start^=p.first;
      if(p.second!=N/3){ok=false;}
    }
    if(start==0&&ok){ans=true;}
    }
  if(ans){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
 return 0;
}