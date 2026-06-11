#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main() {
  int N; cin>>N;
  int Ans=N;
  int m;
  REP(i,N) {
    int now; cin>>now;
    if (i==0) {
      m=now;
    }
    if (now>m) Ans--;
    m=min(now,m);
  }
  cout << Ans << "\n";
  return 0;
}
