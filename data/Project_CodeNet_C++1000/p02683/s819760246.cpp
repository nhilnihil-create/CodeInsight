#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll>> A(N, vector<ll>(M, 0));
    for (int i = 0; i<N; ++i){
      cin >> C[i];
      for (int j = 0; j < M; j++) cin >> A[i][j];
    }

    bool no = true;
    ll cost_min = 9223372036854775807;

    for (int bit = 0; bit < (1 << N); ++bit) {
      vector<ll> total(M, 0);
      ll cost = 0;
      for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
          for (int j = 0; j < M; j++){
            total[j] += A[i][j];
          }
          cost += C[i];
        }
      }
      bool check = true;
      for (int j = 0; j < M; ++j) {
        if (total[j] < X) check = false;
      }
      if (check) {
        cost_min = min(cost_min, cost);
        no = false;
      }
    }

    if(no) cout << -1 << endl;
    else cout << cost_min << endl;
    return 0;
}