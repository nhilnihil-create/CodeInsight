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
  string s;
  cin>>N>>s;
  int ans=0;
  for(int i=0;i<1000;i++){
    string t;
    int x=i;
    for(int j=0;j<3;j++){
      t+=(x%10+'0');
      x/=10;
    }
    int v=0;
    for(int j=0;j<N;j++){
      if(s[j]==t[v]){
        v++;
      if(v==3){break;}
      }
    }
    if(v==3){ans++;}
  }
  cout<<ans<<endl;
  return 0;
}