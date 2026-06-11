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
  ll N,ans=0;
  cin>>N;
  set<ll> S;
  for(int i=2; i<=sqrt(N); ++i){
    ll P=N;
    while(P%i==0) P/=i;
    if(P%i==1) S.insert(i);
  }
  for(int i=2; i<=sqrt(N-1); ++i){
    if((N-1)%i==0){
      S.insert(i);
      if(N-1!=i) S.insert((N-1)/i);
    }
  }
  if(N>2) S.insert(N-1);
  S.insert(N);
  ans=S.size();
  co(ans);
  return 0;
}