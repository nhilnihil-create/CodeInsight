#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int dep[100005];
vector<int> ch[100005];
int par[100005];
void f(int v) {
  for(int to : ch[v]){
    par[to] = v;
    dep[to] = dep[v] + 1;
    f(to);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  bool isRoot[N];
  FOR(i,0,N) isRoot[i] = true;
  FOR(i,0,N){
    int id, k;
    cin>>id>>k;
    FOR(j,0,k){
      int c;
      cin>>c;
      ch[id].push_back(c);
      isRoot[c] = false;
    }
  }
  int root = 0;
  FOR(i,0,N) {
    if(isRoot[i]) {
      root = i;
      break;
    }
  }
  par[root] = -1;
  f(root);
  FOR(i,0,N){
    string type;
    if(i == root) type = "root";
    else if(ch[i].size()==0) type = "leaf";
    else type = "internal node";
    cout<<"node "<<i<<": parent = "<<par[i]<<", depth = "<<dep[i]<<", "<<type<<", [";
    FOR(j,0,ch[i].size()){
      if(j) cout<<", ";
      cout<<ch[i][j];
    }
    cout<<"]"<<endl;
  }
}
