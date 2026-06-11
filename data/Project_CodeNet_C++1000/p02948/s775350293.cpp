#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<P> aru(n);
  for(int i=0; i<n; ++i){
    int a, b;
    cin >> a >> b;
    aru[i] = make_pair(a,b);
  }
  sort(aru.begin(),aru.end());
  int ans = 0;
  int arui = 0;
  priority_queue<int> que;
  for(int i=1; i<=m; ++i){
    //cout << i << ':';
    while(arui < n && i == aru[arui].first){
      que.push(aru[arui].second);
      //cout << aru[arui].second << " ";
      ++arui;
    }
    //cout << endl;
    if(!que.empty()){
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << endl;
}