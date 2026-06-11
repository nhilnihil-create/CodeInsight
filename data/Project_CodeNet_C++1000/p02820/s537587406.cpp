#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;



int main() {
  int n,k,r,s,p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  
  vector<int> cr(n,0),cs(n,0),cp(n,0);
  int tr=0,ts=0,tp=0;
  rep(i,k){
    if(t[i]=='r'){
      tr++;
      cr[i]=1;
    }
    else if(t[i]=='s'){
      ts++;
      cs[i]=1;
    }
    else if(t[i]=='p'){
      tp++;
      cp[i]=1;
    }
  }
  for(int i=k;i<n;i++){
    if(t[i]=='r' && cr[i-k]==0){
      tr++;
      cr[i]=1;
    }
    else if(t[i]=='s' && cs[i-k]==0){
      ts++;
      cs[i]=1;
    }
    else if(t[i]=='p' && cp[i-k]==0){
      tp++;
      cp[i]=1;
    }
  }
  
  cout<<tr*p+ts*r+tp*s<<endl;
    
  return 0;
}