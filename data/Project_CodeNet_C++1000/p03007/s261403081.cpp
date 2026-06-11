#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  int ans = A[0];
  int tmp = A[N-1];
  queue<int> q;;
  for(int i = 1; i < N-1; i++){
    q.push(A[i]);
  }
  vector<pair<int, int> > a;
  while(!q.empty()){
    if(q.front() < 0){
      a.push_back({ans, q.front()});
      ans = ans - q.front();
      q.pop();
    }else{
      a.push_back({tmp, q.front()});
      tmp = tmp - q.front();
      q.pop();
    }
  }
  a.push_back({ans, tmp});
  ans = ans - tmp;
  cout << ans << endl;
  REP(i, N-1){
    cout << a[i].first << " " << a[i].second << endl;
  }
}
