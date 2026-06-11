#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main(){
  int N; cin >> N;
  int Amax = 1e6;
  vector<int> A(N);
 
  vector<bool> P(Amax+1,true); //倍数テーブル
  map<int,int> mp;
  
  REP(i,N) cin >> A.at(i);
  sort(A.begin(),A.end());
  
  //エラトステネス的なやつ
  REP(i,N){
    mp[A.at(i)]++;
    if(mp[A.at(i)]>1) continue;
    if(!P.at(A.at(i))) continue;
    int t = 2;
    while(A.at(i)*t<=Amax){
      P.at(A.at(i)*t) = false;
      ++t;
    }
  }
 
  int ans=0;
 
  REP(i,N){
    if(mp[A.at(i)]>1)continue;
    if(P.at(A.at(i)))ans++;
  }
 
  cout << ans << endl;
 
  return 0;
}
