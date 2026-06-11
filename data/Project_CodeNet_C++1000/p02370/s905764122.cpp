// ????????°????????????????????????????????????????±???????O(|V|^2)?:cycledetectDirected()
#include <algorithm>
#include <vector>
#include <cfloat>
#include <string>
#include <cmath>
#include <set>
#include <cstdlib>
#include <map>
#include <ctime>
#include <iomanip>
#include <functional>
#include <deque>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
#include <climits>
#include <sys/time.h>
#include <cctype>

using namespace std;

typedef long long ll;

// ????????°????????§??°
#define MAX_V 100000
// ??°????????????????????°
int V;
vector <int> graph[MAX_V];
bool vis[MAX_V];
vector <int> list;
int indeg[MAX_V];

void topologicalsort() {
  memset(indeg, 0, sizeof(indeg));
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      int p = graph[i][j];
      indeg[p]++;
    }
  }

  for (int i = 0; i < V; i++) {
    if (indeg[i] == 0 && !vis[i]) {
      queue<int> que;
      que.push(i);
      vis[i] = true;
      while (!que.empty()) {
	int p = que.front(); que.pop();
	list.push_back(p);

	for (int j = 0; j < graph[p].size(); j++) {
	  int np = graph[p][j];
	  indeg[np]--;
	  if (vis[np]) continue;
	  if (indeg[np] == 0) {
	    vis[np] = true;
	    que.push(np);
	  }
	}
      }
    }
  }
}

int main() {
  int E;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    graph[s].push_back(t);
  }
  topologicalsort();

  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << endl;
  }
}