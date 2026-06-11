#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<pair<int, int> > ans;
  int idx1 = 0, idx2 = M+1;
  int step = M;
  REP(i, (M+1)/2){
    ans.push_back({idx1+1, idx1+step+1});
    idx1++;
    step--;
    if(step == 0) continue;
    ans.push_back({idx2+1, idx2+step+1});
    idx2++;
    step--;
  }
  for(auto i : ans){
    cout << i.first << " " << i.second << endl;
  }
}