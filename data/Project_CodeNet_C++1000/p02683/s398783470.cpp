#include <bits/stdc++.h>

#include <fstream>
using namespace std;
int N, M, X;
vector<long long> cost(13);
vector<vector<long long>> kouka(13, vector<long long> (13));
long long minn = 99999999999;

void dfs(int k, vector<long long> rikaido, int sum){
  if(k == N){
    bool done = true;
    for(int i = 0; i < M; i++){
      if(rikaido[i] < X){
        done = false;
      }
    }
    if(done && sum < minn){
      minn = sum;
    }
    return ;
  }

  for(int i = 0; i < M; i++){
    rikaido[i] += kouka[k][i];
  }
  dfs(k+1, rikaido, sum + cost[k]);
  for(int i = 0; i < M; i++){
    rikaido[i] -= kouka[k][i];
  }
  dfs(k+1, rikaido, sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  cin >> N >> M >> X;
  for(int i = 0; i < N; i++){
    cin >> cost[i];
    for(int j = 0; j < M; j++){
      cin >> kouka[i][j];
    }
  }
  vector<long long> rikaido(13);
  dfs(0, rikaido, 0);
  if(minn == 99999999999){
    cout << -1 <<endl;
  } else{
    cout << minn <<endl;
  }
}
