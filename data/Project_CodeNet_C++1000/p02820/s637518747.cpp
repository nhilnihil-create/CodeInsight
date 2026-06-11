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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;


int main(){
  ll N,K,R,S,P,ans=0;
  string T;
  cin>>N>>K>>R>>S>>P>>T;
  
  ll CAN=1;
  
  for(int i=0; i<K; ++i){
    CAN=1;
    for(int j=0; j<=N/K+1; ++j){
      if(i+j*K<N){
        if(j>0 && T.at(i+(j-1)*K)==T.at(i+j*K)) CAN*=-1;
        if(j>0 && T.at(i+(j-1)*K)!=T.at(i+j*K)) CAN=1;
        if(T.at(i+j*K)=='r' && CAN>0) ans+=P;
        if(T.at(i+j*K)=='s' && CAN>0) ans+=R;
        if(T.at(i+j*K)=='p' && CAN>0) ans+=S;
      }
    }
  }
  
  co(ans);
  return 0;
}