#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cfloat>
using namespace std;
bool visited[100000];
vector <int> edges[100000];
void dfs(int cur){
  visited[cur] = true;
  for(int i = 0; i < edges[cur].size(); i++){
    int next = edges[cur][i];
    if(!visited[next]){
      dfs(next);
    }
  }
}

int main(){
  int N;
  int M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int A;
    int B;
    cin >> A >> B;
    edges[A - 1].push_back(B - 1);
    edges[B - 1].push_back(A - 1);
  }

  int cc_no = 0;
  for(int i = 0; i < N; i++){
    if(!visited[i]){
      cc_no ++;
      dfs(i);
    }
  }
  cout << cc_no - 1 << endl;
  return 0;
}
