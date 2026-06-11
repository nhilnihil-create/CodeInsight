#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int M = 1e9+7;
int n, k;
vector<int> edge[110000];
queue<int> q;
bool done[110000];
long long ans;

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  done[1] = true;
  ans = k;
  
  int cnt = 0;
  for (int v: edge[1]) {
    q.push(v);
    done[v] = true;
    ans = ans * (k-cnt-1) % M;
    cnt++;
  }
  
  while(q.size()) {
    int u = q.front(), cnt = 0;
    for (int v: edge[u]) {
      if (done[v]) continue;
      q.push(v);
      done[v] = true;
      ans = ans * (k-cnt-2) % M;
      cnt++;
    }
    q.pop();
  }
  
  cout << ans << endl;
  return 0;
}