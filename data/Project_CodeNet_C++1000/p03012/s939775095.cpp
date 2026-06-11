#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i < (int)(n+1); i++)
#define N_MAX 110
#define K_MAX 100010

const int INF = 1001001001;

int main() {
  int N;
  cin >> N;
  
  vector<int> W(N);
  rep(i,N){
    cin >> W.at(i);
  }

  int res = INF;
  for(int t = 0; t < N; t++){
    int S1 = 0;
    int S2 = 0;
    for(int i = 0; i <= t; i++){
      S1 += W.at(i);
    }
    for(int i = t+1; i <N ; i++){
      S2 += W.at(i);
    }
    res = min(res,abs(S1-S2));
  }

  cout << res << endl;
}