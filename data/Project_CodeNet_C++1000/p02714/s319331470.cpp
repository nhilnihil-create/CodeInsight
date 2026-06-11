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
  string s;
  cin>>N>>s;
  map<char,int64_t>k;
  for(int i=0;i<N;i++){
    k[s[i]]++;
  }
  int64_t sum=k['R']*k['G']*k['B'];
  int64_t cnt=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(2*j-i<N){
        if(s[2*j-i]!=s[i]&&s[2*j-i]!=s[j]&&s[i]!=s[j]){
          cnt++;
        }
      }
    }
  }
  cout<<sum-cnt<<endl;
  return 0;
}