#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<vector<ll>> v(10, vector<ll>(10,0));

  for(int i = 1; i <= N; i++){
    string now = to_string(i);
    int h = now[0] - '0';
    int t = now[now.size()-1] - '0';
    v[h][t]++;
  }
  ll ans = 0;
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      ans += v[i][j] * v[j][i];
    }
  }
  cout << ans << endl;
}
