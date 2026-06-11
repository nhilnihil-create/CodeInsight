#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> a(n);
  for (int i = 0; i < m; ++i) {
    int b, c;
    cin >> b >> c;
    a[b - 1].insert(c - 1);
    a[c - 1].insert(b - 1);
  }
  deque<int> d;
  vector<bool> seen;
  int summ=0;
  seen.assign(n, false);
  int v;
  int count=0;
  for(int j=0;j<n;++j){
    v=j;
    if(seen[v])continue;
    count=0;
    seen[v] = true;
    while (1) {
      ++count;
      for (auto i:a[v]) {
        if(!seen[i])d.push_back(i);
        seen[i]=true;
      }
      if (!d.empty()) {
        v = d.front();
        d.pop_front();
//        cout<<v<<" "<<count<<endl;
      }else {
        break;
      }
    }
    summ=max(summ,count);
  }
  cout<<summ<<endl;
}