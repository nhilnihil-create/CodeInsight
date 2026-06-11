#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ccp(vector<int>& c, int n, int m){
  sort(c.begin(), c.end());
  vector<vector<int> > t(m, vector<int>(n + 1));
  for(int i = 0; i < m; i++){
    t[i][0] = 0;
  }
  for(int j = 0; j <= n; j++){
    t[0][j] = j;
  }
  for(int i = 1; i < m; i++){
    for(int j = 0; j <= n; j++){
      if(j - c[i] < 0) t[i][j] = t[i - 1][j];
      else t[i][j] = min(t[i - 1][j], t[i][j - c[i]] + 1);
    }
  }
  cout << t[m - 1][n] << endl;
  return;
}

void kp(vector<int>& v, vector<int>& w, int N, int W){
  vector<pair<int, int> > k(N);
  for(int i = 0; i < N; i++){
    k[i].second = v[i];
    k[i].first = w[i];
  }
  sort(k.begin(), k.end());
  vector<vector<int> > t(N, vector<int>(W + 1));
  for(int i = 0; i < N; i++){
    t[i][0] = 0;
  }
  for(int i = 0; i <= W; i++){
    if(i >= k[0].first) t[0][i] = k[0].second;
    else t[0][i] = 0;
  }
  for(int i = 1; i < N; i++){
    for(int j = 0; j <= W; j++){
      if(j - k[i].first < 0) t[i][j] = t[i - 1][j];
      else t[i][j] = max(t[i - 1][j], t[i - 1][j - k[i].first] + k[i].second);
    }
  }
  cout << t[N - 1][W] << endl;
}

void lis(vector<int>& a){
  int n = a.size();
  vector<int> l(n);
  l[0] = a[0];
  int lid = 1;
  for(int i = 1; i < n; i++){
    int x = a[i];
    auto it = lower_bound(l.begin(), l.begin() + lid, x);
    int pos = (int)(it - l.begin());
    if(pos == lid){
      l[lid++] = x;
    }
    else *it = x;
    /*for(int i = 0; i < l.size(); i++){
      cout << l[i] << " ";
    }
    cout << endl;*/
  }
  cout << lid << endl;
}

void solve(){
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  lis(v);
}

int main(){
  solve();
  return 0;
}

