#include <iostream>
#include <vector>

using namespace std;

const int M = 1e9+7;
int n, k;
long long ans;
vector<int> edge[110000];
bool done[110000];

void dfs(int u)
{
  done[u] = true;
  int sibling = 0;
  for (int v: edge[u]) {
    if (done[v]) continue;
    done[v] = true;
    int color = k - sibling - 1;
    sibling++;
    if (u != 1) color--;
    ans = ans * color % M;
    dfs(v);
  }
}

int main()
{
  cin >> n >> k;
  
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  ans = k;
  dfs(1);
  
  cout << ans << endl;
  return 0;
}