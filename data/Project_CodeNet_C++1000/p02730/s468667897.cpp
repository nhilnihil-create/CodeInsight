#include <bits/stdc++.h>
using namespace std;
#include <math.h>
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
  cin>>s;
  int ans=0;
  int n=s.size();
 
  bool ok1=true;
  for(int i=0;i<n;i++){
     if(s[i]!=s[n-1-i]){
       ok1=false;
     }
   }
  bool ok2=true;
  int k=(n-1)/2;
  for(int i=0;i<k;i++){
     if(s[i]!=s[k-1-i]){
       ok2=false;
     }
   }  
  bool ok3=true;
  int d=(n+3)/2;
  for(int i=d-1;i<n-1;i++){
     if(s[i]!=s[n-1-i]){
       ok2=false;
     }
   }
   
  if(ok1&&ok2&&ok3){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}