#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i = 0; i < n ; i++)
#define pb push_back
static const int MAX = 100000;
static const int INF = 1000000;

typedef pair<int, int> P;
typedef pair<P, int> PP;

int main(void){
  int V,E; cin >> V >> E;
  vector<int> list[MAX]; int into[V];
  int a,b;
  rep(i,V){
    into[i] = 0;
  }
  rep(i,E){
    cin >> a >> b;
    list[a].pb(b);
    into[b] += 1;
  }
  queue<int> Q;
  rep(i,V){
    if (into[i] == 0) Q.push(i);
  }

  while(!Q.empty()){
      cout << Q.front() << endl;

      //cout << endl;

      rep(i,list[Q.front()].size()){
        into[list[Q.front()][i]] -= 1;
        if(into[list[Q.front()][i]] == 0) Q.push(list[Q.front()][i]);
      }


      Q.pop();
  }




  return 0;
}