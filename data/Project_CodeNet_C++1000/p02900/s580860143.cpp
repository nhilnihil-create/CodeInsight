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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

ll N,M,K,A,B,C,ans=0,cnt=0;
string S,T;
vector<int> P,Q;
vector<pair<int,int>> PP;
bool CAN=false,CAN2=true;



ll gcd(ll a,ll b){
		if (a%b==0){
			return(b);
    	}
		else{
			return(gcd(b,a%b));
    	}
}




int main(){
  cin>>A>>B;
  N=gcd(A,B);
  
  if(N==1){
    cout<<1<<endl;
    return 0;
  }
  
  for(ll i=2; i<=N; ++i){
    while(N%i==0){
      N/=i;
      CAN=true;
    }
    if(CAN){
      ans++;
      CAN=false;
      CAN2=false;
    }
    if(i*i>N){
      if(N!=1) ans++;
      break;
    }
    if(N==1) break;
  }
  
  
  if(CAN2){
    cout<<2<<endl; //Nが素数
    return 0;
  }
  cout<<ans+1<<endl;
}