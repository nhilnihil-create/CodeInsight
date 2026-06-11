#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N,M; cin >> N >> M;
  priority_queue<pii,vector<pii>,greater<pii>> pque;
  priority_queue<int> que;
  for(int i=0;i<N;i++){
    int a,b; cin >> a >> b;
    pque.push(make_pair(a,b));
  }
  int ans = 0;
  for(int i=1;i<=M;i++){
    while(!pque.empty()){
      pii p = pque.top();
      if(p.first>i) break;
      pque.pop();
      que.push(p.second);
    }
    if(!que.empty()){
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << endl;
}
