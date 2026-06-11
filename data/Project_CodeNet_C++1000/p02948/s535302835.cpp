#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<pair<int, int>> g;
int main() {
  int n,m;
  cin >> n >> m;
  int a,b;
  
  for(int i =0;i<n;i++){
    cin >> a >> b;
    g.push_back(make_pair(a,b));
  }
  sort(g.begin(), g.end());
  //降順のpq
  priority_queue<int> pq;
  int j = 0;
  long long res = 0;
  for(int i = 1;i< m+1;i++){
    while(j< n && g[j].first<= i ){
      pq.push(g[j].second);
      j+=1;
    }
    if(pq.size() > 0){
      res += pq.top();
      pq.pop();
    }
    
  }
  cout << res;
}
