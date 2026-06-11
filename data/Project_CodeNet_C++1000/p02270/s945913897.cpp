#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int n,k,w[100010];

bool check(int x){
  int cnt = 1,sum=0;
  rep(i,n){
    if( w[i] > x ) return false;
    if( sum + w[i] <= x ) sum += w[i];
    else{
      sum = w[i];
      cnt++;
    }
  }
  return cnt <= k;
}

int main(){
  cin >> n >> k;
  rep(i,n) cin >> w[i];
  int L=0,R=100000*10000+10,M=0;
  while(L+1<R){
    M = ( L + R ) / 2;
    if( check(M) ) R = M;
    else           L = M;
  }
  cout << R <<endl;
  return 0;
}