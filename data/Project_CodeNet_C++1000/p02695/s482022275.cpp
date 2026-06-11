#include <bits/stdc++.h>
using namespace std;

int M, N;

void dfs(int i, int limit, vector<int> &keep, vector<vector<int>> &array, int &count) {
  if(i == N) {
    for(int j = limit; j <= M; j++) {
      keep.at(i - 1) = j;
      for(int l = 0; l < N; l++) {
        array.at(count).at(l) = keep.at(l);
      }
      count++;
    }
  }
  else {
    for(int j = limit; j <= M; j++) {
      keep.at(i - 1) = j;
      dfs(i + 1, j, keep, array, count);
    }
  }
}

int main() {
  int Q;
  cin >> N >> M >> Q;
  map<tuple<int, int, int>,int> data;
  for(int i = 0; i < Q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    data[make_tuple(a, b, c)] = d;
  }
  int64_t total = 1;
  for(int i = N + M - 1; i >= M; i--) {
    total *= i;
  }
  for(int i = 2; i <= N; i++) {
    total /= i;
  }
  vector<vector<int>> array(total, vector<int> (N));
  vector<int> keep(N);
  int count = 0;
  dfs(1, 1, keep, array, count);
  int ans = 0;
  for(int i = 0; i < total; i++) {
    int sum = 0;
    for(int k = 0; k < N; k++) {
      for(int l = k + 1; l < N; l++) {
        if(data.count(make_tuple(k + 1, l + 1, array.at(i).at(l) - array.at(i).at(k)))) {
          sum += data[make_tuple(k + 1, l + 1, array.at(i).at(l) - array.at(i).at(k))];
        }
      }
    }
    if(sum > ans) {
      ans = sum;
    }
  }
  cout << ans << endl;     
}