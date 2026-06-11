#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};


int main(){
  map<int,int> m;
  ll n;
  cin >> n;
  repc(i, 2, sqrt(n)){
    while(n % i == 0){
      m[i]++;
      n = n / i;
    }
  }
  if(n > 1) m[n]++;
  int ans = 0;
  for(auto it : m){
    int p = it.sd;
    int curr = 1;
    while(p >= curr){
      ans++;
      p -= curr;
      curr++;
    }
  }
  cout << ans << endl;
  return 0;
}