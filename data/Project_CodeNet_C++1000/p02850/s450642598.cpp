#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<vector<int>> Tree(MAXN);
map<pair<int, int>, int> Colors;
int K = 0;

void dfs(int curNode, int prevNode, int prevColor)
{
  vector<int> nextNodes = Tree.at(curNode);
  int nextColor = 1;
  for (int i = 0; i < nextNodes.size(); i++)
  {
    int nextNode = nextNodes.at(i);
    if (nextNode == prevNode)
      continue;
    if (nextColor == prevColor)
      nextColor++;
    int a = curNode, b = nextNode;
    if (a > b)
      swap(a, b);
    Colors[make_pair(a, b)] = nextColor;
    dfs(nextNode, curNode, nextColor);
    K = max(K, nextColor);
    nextColor++;
  }
}

int main()
{
  int N, a, b;
  cin >> N;
  vector<pair<int, int>> vp;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    Tree.at(a).push_back(b);
    Tree.at(b).push_back(a);
    vp.push_back(make_pair(a, b));
  }
  dfs(1, 0, 0);
  cout << K << endl;
  for (int i = 0; i < N - 1; i++)
  {
    tie(a, b) = vp.at(i);
    cout << Colors.at(make_pair(a, b)) << endl;
  }
}