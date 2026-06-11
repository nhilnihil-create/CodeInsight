#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  string S;
  cin >> S;
  
  vector<ll> A(S.size()+1);
  
  vector<ll> B;
  ll cnt = 1;
  REP(i,S.size()-1){
    if(S.at(i)!=S.at(i+1)){
      B.push_back(cnt);
      cnt = 1;
      continue;
    }
    cnt++;
  }
  B.push_back(cnt);
  // REP(i,B.size()){
  //   cout << B.at(i);
  // }
  if(S.at(0) == '<'){
    if(B.size()%2==0){
      ll sum = 0;
      REP(i,B.size()/2){
        ll x = min(B.at(i*2),B.at(i*2+1));
        ll y = max(B.at(i*2),B.at(i*2+1));
        sum+=(x-1)*x/2+y*(y+1)/2;
      }
      cout << sum << endl;
    }else{
      ll sum = 0;
      REP(i,(B.size()-1)/2){
        ll x = min(B.at(i*2),B.at(i*2+1));
        ll y = max(B.at(i*2),B.at(i*2+1));
        sum+=(x-1)*x/2+y*(y+1)/2;
      }
      cout << sum + B.at(B.size()-1)*(B.at(B.size()-1)+1)/2 << endl;
    }
  }else{
    if(B.size()%2==0){
      ll sum = 0;
      FOR(i,1,B.size()/2){
        ll x = min(B.at(i*2-1),B.at(i*2));
        ll y = max(B.at(i*2-1),B.at(i*2));
        sum+=(x-1)*x/2+y*(y+1)/2;
      }
      cout << sum + B.at(0)*(B.at(0)+1)/2 + B.at(B.size()-1)*(B.at(B.size()-1)+1)/2 << endl;
    }else{
      ll sum = 0;
      FOR(i,1,(B.size()-1)/2+1){
        ll x = min(B.at(i*2-1),B.at(i*2));
        ll y = max(B.at(i*2-1),B.at(i*2));
        sum+=(x-1)*x/2+y*(y+1)/2;
      }
      cout << sum + B.at(0)*(B.at(0)+1)/2 << endl;
    }
  }
}