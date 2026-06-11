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
  int N,A,B,C,D;
  string s;
  cin>>N>>A>>B>>C>>D>>s;
  bool ok1=true;
  for(int i=B-1;i<D;i++){
    if(s[i]=='#'&&s[i+1]=='#'){ok1=false;}
  }
  for(int i=A-1;i<C;i++){
    if(s[i]=='#'&&s[i+1]=='#'){ok1=false;}
  }
  if(!ok1){cout<<"No"<<endl;return 0;}
  bool ok2=false;
  for(int i=B-1;i<D;i++){
    if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){ok2=true;}
  }
  if(C>D){
    if(!ok2){cout<<"No"<<endl;return 0;}}
  cout<<"Yes"<<endl;
  return 0;
}