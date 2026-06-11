#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define co(ans) cout<<ans<<endl;
#define COYE cout<<"YES"<<endl;
#define COYe cout<<"Yes"<<endl;
#define COye cout<<"yes"<<endl;
#define CONO cout<<"NO"<<endl;
#define CONo cout<<"No"<<endl;
#define COno cout<<"no"<<endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
#define MAX 5100000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

int main(){
  ll N,K,C,ans=0;
  string S;
  cin>>N>>K>>C>>S;
  
  ll L[K],R[K]; // L[i]=仕事iが可能な日にちの最小値,R[i]=仕事iが可能な日にちの最大値
  ll cnt=0;
  for(ll i=0; i<N; ++i){
    if(S[i]=='o'){
      L[cnt]=i;
      cnt++;
      i+=C;
    }
    if(cnt==K) break;
  }
  cnt=K-1;
  for(ll i=N-1; i>=0; --i){
    if(S[i]=='o'){
      R[cnt]=i;
      cnt--;
      i-=C;
    }
    if(cnt==-1) break;
  }
  
  REP(i,K){
    if(L[i]==R[i]) co(L[i]+1);
  }
  cout<<endl;
  return 0;
}