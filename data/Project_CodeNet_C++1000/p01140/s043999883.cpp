#include<iostream>
#include<map>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int solve(int n,int m,int *h,int *w){
  map<int,int> M;
  rep(i,m){//length
    int tmp=0;
    rep(j,i+1){
      tmp+=w[j];
    }
    M[tmp]++;
    REP(j,i+1,m){
      tmp=tmp-w[j-i-1]+w[j];
      //cout << "tmp"<<tmp << endl;
      M[tmp]++;
    }
  }

  int ret = 0;
  rep(i,n){
    int tmp=0;
    rep(j,i+1){
      tmp+=h[j];
    }
    ret+=M[tmp];
    REP(j,i+1,n){
      tmp=tmp-h[j-i-1]+h[j];
     ret+=M[tmp];
    }
  }
  return ret;
}

main(){
  int n,m;
  while(cin>>n>>m && n){
    int h[n],w[m];
    rep(i,n)cin>>h[i];
    rep(j,m)cin>>w[j];
    cout << solve(n,m,h,w) << endl;
  }
}