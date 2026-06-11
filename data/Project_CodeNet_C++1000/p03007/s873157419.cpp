#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
  int N; long A; cin >> N; multiset<long> S;
  REP(i, N){ cin >> A; S.insert(A); }
  long L, R, a, b; vector<vector<long>> ans;
  REP(i, N-1){ 
    L=*S.begin(); R=*S.rbegin(); a=R-L; b=L-R;
    S.erase(S.find(L)); S.erase(S.find(R));
    if(S.size()){
      long l=*S.begin(), r=*S.rbegin(), m=max(abs(a-l), abs(a-r)), n=max(abs(b-l), abs(b-r));
      if(m>=n){ S.insert(a); ans.push_back({R, L}); }else{ S.insert(b); ans.push_back({L, R}); }
    }else{ cout << a << "\n"; ans.push_back({R, L}); }
  }
  REP(i, N-1){ cout << ans[i][0] << " " << ans[i][1] << "\n"; }
}