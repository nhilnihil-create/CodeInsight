#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 201;
const int DX[] = {-1,0,1,0};
const int DY[] = {0,1,0,-1};
int N;
int X[MAX_N], Y[MAX_N];

int main() {
  X[0] = Y[0] = 0;
  while(cin >> N && N) {
    int sx,sy,ex,ey;
    sx = sy = 0;
    ex = ey = 1;
    vector<pair<pair<int,int>,int> > Q;
    for(int i = 1; i < N; ++i) {
      int n, d;
      cin >> n >> d;
      Q.push_back(make_pair(make_pair(n,d),i));
    }
    sort(Q.begin(), Q.end());
    for(int i = 0; i < Q.size(); ++i) {
      int p = Q[i].second;
      int t = Q[i].first.first;
      int d = Q[i].first.second;
      X[p] = X[t] + DX[d];
      Y[p] = Y[t] + DY[d];
      sx = min(sx,X[p]);
      sy = min(sy,Y[p]);
      ex = max(ex,X[p]+1);
      ey = max(ey,Y[p]+1);
    }
    cout << ex-sx << " " << ey-sy << endl;
  }
  return 0;
}