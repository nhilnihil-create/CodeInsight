#include <bits/stdc++.h>

#include <fstream>
using namespace std;

const int INF = 1001001001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
     ifstream in("input.txt");
     cin.rdbuf(in.rdbuf());
  //*/
  long long N, K;
  cin >> N >> K;
  vector<vector<int>> dl(60, vector<int>(N));
  for(int i = 0; i < N; i++){
    cin >> dl[0][i];
    dl[0][i]--;
  }
  for(int i = 1; i < 60; i++){
    for(int j = 0; j < N; j++){
      dl[i][j] = dl[i-1][dl[i-1][j]];
    }
  }
  int now = 0;
  for(int i = 0; i < 60; i++){
    if(K>>i&1ll){
      now = dl[i][now];
    }
  }
  cout << now + 1<<endl;
}
