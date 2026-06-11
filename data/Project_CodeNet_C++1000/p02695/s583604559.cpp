#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

using namespace std;

int n,m,q;
vector<int> a,b,c,d;
int recFunc(int dep, vector<int> v, int mx, int mxScore){
  if (dep<n){
    for (int t=mx; t<=m; t++){
      int score=0;
      vector<int> u; u=v;
      u.push_back(t);
      score = recFunc(dep+1, u, t, mxScore);
      mxScore = MAX(mxScore, score);
    }
    return mxScore;
  } else {
    int score = 0;
//    for (int i=0; i<n; i++) cout << v[i] << " ";
//    cout << endl;
    for (int i=0; i<q; i++){
      if (v[b[i]-1]-v[a[i]-1] == c[i]) score += d[i];
    }
    return MAX(mxScore, score);
  }
}

int main(void){  
  cin >> n >> m >> q;
  for (int i=0; i<q; i++){
    int ta, tb, tc, td;
    cin >> ta >> tb >> tc >> td;
    a.push_back(ta); b.push_back(tb);
    c.push_back(tc); d.push_back(td);
  }
  cout << recFunc(0, vector<int>(), 1, 0) << endl;
  return 0;
}