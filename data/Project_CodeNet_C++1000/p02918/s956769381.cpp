#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N,K; cin>>N>>K;
  string S; cin>>S;
  
  ll count=0;
  rep(i,N){
    if(S[i]=='L'&&(i==0||S[i-1]=='R')) count++;
    else if(S[i]=='R'&&(i==N-1||S[i+1]=='L')) count++;
  }
  
  count=max((ll)1,count-2*K);
  
  cout<<N-count<<endl;
  return 0;
}