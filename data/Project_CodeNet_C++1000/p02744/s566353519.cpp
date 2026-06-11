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
int N;
void dfs(string s,char MAX){
  if(s.size()==N){
    cout<<s<<endl;
    return;
  }
  for(char c='a';c<=MAX+1;c++){
    string t=s;
    t+=c;
    char m=max(c,MAX);
    dfs(t,m);
  }
}


int main() {
  cin>>N;
  dfs("",'a'-1);
  return 0;
}