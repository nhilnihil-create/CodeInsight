#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for(int i = 0; i < n; i++){
    long long x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  
  vector<vector<pair<long long, long long>>> e(n, vector<pair<long long, long long>>(n));
  for(int i = 0; i < n - 1; i++){
    e[i][i] = make_pair(0, 0);
    for(int j = i + 1; j < n; j++){
      long long dx = v[i].first - v[j].first;
      long long dy = v[i].second - v[j].second;
      if(dx < 0){
        dx = -dx;
        dy = -dy;
      }if(dx == 0 && dy < 0){
        dy = -dy;
      }
      e[i][j] = make_pair(dx, dy);
      e[j][i] = make_pair(dx, dy);
    }
  }
  unordered_map<string, int> counter;
  int max = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      string s = to_string(e[i][j].first) + "_" + to_string(e[i][j].second);
      int c;
      if(counter.count(s)){
        c = counter[s];
        counter.erase(s);
        c++;
      }else{
        c = 1;
      }
      counter.emplace(s, c);
      if(c > max) max = c;
    }
  }
  
  cout << n - max << endl;
  
  return 0;
}
