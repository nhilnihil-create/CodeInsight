#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main() {
  string Ans;
  int N,K,Q; cin>>N>>K>>Q;
  vector<int> p(N,K);
  REP(i,Q) {
    int who; cin>>who;
    who--;
    p.at(who)++;
  }
  REP(i,N){
    p.at(i)-=Q;
    Ans=p.at(i)>0? "Yes" : "No";
    cout << Ans << '\n';
  }
  return 0;
}
