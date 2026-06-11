#include<iostream>
#include<map>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define N 1500001
int is_exist[N]={0};
int cnt[N]={0};
int solve(int n,int m,int *h,int *w,int tc){
  map<int,int> M;
  rep(i,m){//length
    int tmp=0;
    rep(j,i+1){
      tmp+=w[j];
    }
    if( is_exist[tmp]!=tc)is_exist[tmp]=tc,cnt[tmp]=1;
    else cnt[tmp]++;
    REP(j,i+1,m){
      tmp=tmp-w[j-i-1]+w[j];
      if ( is_exist[tmp]!=tc)is_exist[tmp]=tc,cnt[tmp]=1;
      else cnt[tmp]++;
    }
  }

  int ret = 0;
  rep(i,n){
    int tmp=0;
    rep(j,i+1){
      tmp+=h[j];
    }
    if (is_exist[tmp]==tc)ret+=cnt[tmp];
    REP(j,i+1,n){
      tmp=tmp-h[j-i-1]+h[j];
      if ( is_exist[tmp] ==tc)ret+=cnt[tmp];
    }
  }
  return ret;
}

main(){
  int n,m;
  int h[1500],w[1500];
  int tc=0;
  //while(cin>>n>>m && n){
  while(scanf("%d%d",&n,&m) && n){
    tc++;
    rep(i,n)scanf("%d",&h[i]);//cin>>h[i];
    rep(j,m)scanf("%d",&w[j]);//cin>>w[j];
    cout << solve(n,m,h,w,tc) << endl;
  }
}