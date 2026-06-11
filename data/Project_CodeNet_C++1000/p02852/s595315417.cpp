#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,M;
  cin>>N>>M;
  string S;
  cin>>S;
  reverse(S.begin(),S.end());
  vector<int> ans;
  int p = 0;
  bool can = true;
  while(p!=N&&can){
    for(int i = min(N-p,M); i>=1;i--){
      if(S[p+i]=='0') {
        ans.push_back(i);
        p+=i;
        break;
      }
      if(i==1) {
        can = false;
        break;
      }
    }
  }
  reverse(ans.begin(),ans.end());
  if(can){
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
  }
  else cout<<-1<<endl;
}