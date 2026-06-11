#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
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
  string s;
  int Q;
  cin>>s>>Q;
  int y,F;
  char c;
  deque<char>k;
  for(char r:s){k.push_back(r);}
  bool rev=false;
  for(int i=0;i<Q;i++){
    cin>>y;
    if(y==1){
      rev=!rev;
    }
    if(y==2){
      cin>>F>>c;
      if(rev){F=3-F;}
      if(F==1){k.push_front(c);}
      if(F==2){k.push_back(c);}         
    }
  }
  if(rev){
  reverse(k.begin(),k.end());}
  string ans;
  for(char d: k){ans+=d;}
  cout<<ans<<endl;
  return 0;
}