#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

int main(void){
  int N, q;
  cin >> N >> q;
  queue<pair<string, int> > que;
  for(int i=0;i<N;i++){
    int a; string s;
    cin >> s >> a;
    que.push(make_pair<string, int>(s, a));
  }

  int sum = 0;
  while(!que.empty()){
    pair<string, int> qu = que.front();
    que.pop();
    if(qu.second <= q){
      sum += qu.second;
      cout << qu.first << " " << sum << endl;
      continue;
    }
    qu.second -= q;
    sum += q;
    que.push(qu);
  }
  return 0;
}