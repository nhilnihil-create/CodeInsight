#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

vector<vector<int>> adjacentList;
vector<bool> visited;
stack<int> sorted;

void visit(int i) {
  if(visited[i]) return;
  visited[i] = true;
  for(int nn: adjacentList[i]) {
    visit(nn);
  }
  sorted.push(i);
}

int main () {
  int V, E;
  cin >> V >> E;

  adjacentList = vector<vector<int>>(V, vector<int>());
  visited = vector<bool>(V, false);

  REP(i,E) {
    int s, t;
    cin >> s >> t;
    adjacentList[s].push_back(t);
  }

  REP(i, V) visit(i);

  while(!sorted.empty()) {
    cout << sorted.top() << endl;
    sorted.pop();
  }

  return 0;
}