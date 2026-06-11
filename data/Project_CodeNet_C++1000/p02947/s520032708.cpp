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
  int N;
  cin>>N;
  vector<string>s(N);
  map<string,int>k;
  for(int i=0;i<N;i++){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
    k[s[i]]++;
  }
  int64_t sum=0;
  for(auto a:k){
    int64_t c=a.second;
    sum+=(c*(c-1)/2);
  }
  cout<<sum<<endl;
  return 0;
}