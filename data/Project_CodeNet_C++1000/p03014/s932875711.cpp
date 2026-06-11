#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.14159265358979;

int h, w;
char room[2000][2000];
int L[2000][2000], R[2000][2000], D[2000][2000], U[2000][2000];

int main(){
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> room[i][j];
  rep(i, h) rep(j, w){
    if(room[i][j] == '#') L[i][j] = 0;
    else if(j == 0) L[i][j] = 1;
    else L[i][j] = L[i][j-1]+1;
  }
  rep(j, w) rep(i, h){
    if(room[i][j] == '#') U[i][j] = 0;
    else if(i == 0) U[i][j] = 1;
    else U[i][j] = U[i-1][j]+1;
  }
  for(int i = 0; i < h; i++){
    for(int j = w-1; j >= 0; j--){
    if(room[i][j] == '#') R[i][j] = 0;
    else if(j == w-1) R[i][j] = 1;
    else R[i][j] = R[i][j+1]+1;
    }
  }
  for(int j = 0; j < w; j++){
    for(int i = h-1; i >= 0; i--){
    if(room[i][j] == '#') D[i][j] = 0;
    else if(i == h-1) D[i][j] = 1;
    else D[i][j] = D[i+1][j]+1;
    }
  }
  int ans = -INF;
  rep(i, h) rep(j, w) ans = max(ans, L[i][j] + R[i][j] + D[i][j] + U[i][j] - 3);
  cout << ans <<endl;
}

