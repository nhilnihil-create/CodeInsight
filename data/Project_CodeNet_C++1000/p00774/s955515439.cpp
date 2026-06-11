#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;

int W = 5;
int main(){
  while(true){
    int H;
    cin >> H;
    if(H==0) break;
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, H){
      REP(j, W){
        cin >> A[i][j];
      }
    }
    bool deleted = true;
    int ans = 0;
    while(deleted){
      deleted = false;
      REP(i, H){
        REP(j, W-2){
          if(A[i][j] != -1 && A[i][j] == A[i][j+1]&& A[i][j] == A[i][j+2]){
            deleted = true;
            int x = A[i][j];
            ans += x*3;
            A[i][j] = A[i][j+1] = A[i][j+2] = -1;
            FOR(k, j+3, W){
              if(x==A[i][k]){
                ans+=x;
                A[i][k] = -1;
              }
              else{
                break;
              }
            }
          }
        }
      }
      if(deleted){
        REP(j, W){
          REPR(i, H-2){
            if(A[i][j]==-1) continue;
            int h = i;
            while(h+1 < H && A[h+1][j] == -1){
              A[h+1][j] = A[h][j];
              A[h][j] = -1;
              h++;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}


