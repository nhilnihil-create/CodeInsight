#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string S;
  cin >> S;
  ll K;
  cin >> K;
  int sum = 0;
  int cnt = 0;
  REP(i,S.size()-1){
    if(S.at(i)==S.at(i+1)){
      cnt++;
    }
    if(cnt>0&&S.at(i)!=S.at(i+1)){
      sum+=(cnt+1)/2;
      cnt=0;
    }
  }
  if(cnt>0){
    sum+=(cnt+1)/2;
  }
  int sum2 = 0;
  int cnt2 = 0;
  string T=S+S;
  REP(i,T.size()-1){
    if(T.at(i)==T.at(i+1)){
      cnt2++;
    }
    if(cnt2>0&&T.at(i)!=T.at(i+1)){
      sum2+=(cnt2+1)/2;
      cnt2=0;
    }
  }
  if(cnt2>0){
    sum2+=(cnt2+1)/2;
  }
  int sum3 = 0;
  int cnt3 = 0;
  string P=S+S+S;
  REP(i,P.size()-1){
    if(P.at(i)==P.at(i+1)){
      cnt3++;
    }
    if(cnt3>0&&P.at(i)!=P.at(i+1)){
      sum3+=(cnt3+1)/2;
      cnt3=0;
    }
  }
  if(cnt3>0){
    sum3+=(cnt3+1)/2;
  }

  if(K%2==1){
    ll y = sum+(sum3-sum)*((K-1)/2);
    cout << y << endl;
  }else{
    ll x = sum+(sum3-sum)*((K-1)/2)+(sum2-sum);
    cout << x << endl;
  }
}