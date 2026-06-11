#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, Q; cin >> N >> Q;
  vector<int> connect[N];
  rep(i,N-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    connect[b].push_back(a);
    connect[a].push_back(b);
  }
  
  int cnt[N] = {};
  rep(j,Q){
    int p, x;
    cin >> p >> x;
    p--;
    cnt[p] += x;
  }

  queue<int> q;
  bool passed[N] = {};
  q.push(0);
  while (!q.empty()){
    auto node = q.front(); q.pop();
    passed[node] = true;
    for (auto n : connect[node]){
      if (passed[n]==false) {
        cnt[n] += cnt[node];
        q.push(n);
      }
    }
  }

  rep(i,N) {
    if (i>0) cout << " ";
    cout << cnt[i];
  }
  cout << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}
