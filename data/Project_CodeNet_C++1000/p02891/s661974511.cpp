#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  string S; cin>>S;
  int K; cin>>K;
  string T=S+S;
  int ans=0;
  rep(i,1,T.size()){
    if(T[i]==T[i-1]){
      ans++;
      T[i]='?';
    }
  }
  int count=1;
  rep(i,1,S.size()){
    if(S[i]==S[i-1]) count++;
    else break;
  }
  if((count%2==1||count==S.size())&&T[T.size()-1]==S[0]){
    ans++;
    ans*=K/2;
    S[0]='?';
    if(K%2==1){
      rep(i,1,S.size()){
        if(S[i]==S[i-1]){
          S[i]='?';
          ans++;
        }
      }
    }
    else ans--;
  }
  else{
    ans*=K/2;
    if(K%2==1){
      rep(i,1,S.size()){
        if(S[i]==S[i-1]){
          S[i]='?';
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
  }
