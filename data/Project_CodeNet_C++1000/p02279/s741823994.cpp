/*! if g++ -g alds_1_7_a.cpp -o alds_1_7_a.out; then ./alds_1_7_a.out < alds_1_7_a.test; fi
 */

#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iterator>
#include <numeric>
#include <functional>
#include <climits>



using namespace std;
typedef unsigned long long ull;
typedef long long ll;

vector<vector<int> > g;
vector<bool> is_child(0);
vector<int> parent(0);
int root_id;
vector<int> depth(0);

void search_child(int n){
  vector<int>& children = g[n];
  for (size_t i = 0; i < children.size(); i++) {
    int child = children[i];
    is_child[child] = true;
    parent[child] = n;
    search_child(child);
  }
}
void calc_depth(int n, int d){
  //cout << "n: " << n << ",\t d: " << d << endl;
  vector<int>& children = g[n];
  depth[n] = d;
  for (size_t i = 0; i < children.size(); i++) {
    calc_depth(children[i], d+1);
  }
}

int main(int argc, char *argv[]){
  size_t n;
  cin >> n;
  g.resize(n);
  for (size_t i = 0; i < n; i++) {
    int id, k, buf;
    cin >> id >> k;
    g[id].resize(k);
    for (size_t j = 0; j < k; j++) {
      cin >> g[id][j];
    }
  }
  is_child.resize(n, false);
  parent.resize(n, -1);
  depth.resize(n, 0);
  for (size_t i = 0; i < n; i++) {
    if(is_child[i]) continue;
    search_child(i);    
  }
  for (size_t i = 0; i < n; i++) {
    if(!is_child[i]) {
      root_id = i;
      break;
    }
  }
  calc_depth(root_id, 0);
  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, %s, [",
           i, parent[i], depth[i],
           !is_child[i] ? "root" : (g[i].size() > 0 ? "internal node" : "leaf"));
    for (int j = 0; j < (int)g[i].size()-1; j++) {
      cout << g[i][j] << ", ";
    }
    if(g[i].size() > 0) cout << g[i].back();
    cout << "]" << endl;;
  }

  return 0;
}