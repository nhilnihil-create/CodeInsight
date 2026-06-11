#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<endl
#define AA(i) cout<<i<<endl
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;

int main(){
  string S; cin >> S;
  ll K; cin >> K;
  ll i, j=1, ans0=0, ans1=0, ans2=0;
  string SS = S + S, SSS = S + S + S;
  if(K!=1){
  rep(i,S.size()-1){
    if(S[i]==S[i+1]) j++;
    else {
      ans0 += j / 2;
      j=1;
    }
  }
  ans0 += j/2;
  j = 1;

  rep(i,SS.size()-1){
    if(SS[i]==SS[i+1]) j++;
    else {
      ans1 += j / 2;
      j=1;
    }
  }
  ans1 += j/2;
  j = 1;

  rep(i,SSS.size()-1){
    if(SSS[i]==SSS[i+1]) j++;
    else {
      ans2 += j / 2;
      j=1;
    }
  }
  ans2 += j/2;
  AA(ans0 + (ans2 - ans0) * ((K - 1) / 2) + (ans1 - ans0) * ((K-1)%2));
  }
  else{
    rep(i,S.size()-1){
    if(S[i]==S[i+1]) j++;
    else {
      ans1 += j / 2;
      j=1;
    }
  }
  ans1 += j/2;
  AA(ans1);
  }
  return 0;
}