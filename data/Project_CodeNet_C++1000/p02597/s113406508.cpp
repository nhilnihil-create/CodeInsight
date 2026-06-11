#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  char c[200000];
  bool f = true;
  rep(i, n){
    cin >> c[i];
    if(c[i] == 'R') f = false;
  }
  //Rがなければ抜ける。
  if(f){
    cout << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  int pos = n-1;
  rep(i, n){
    if(c[i] == 'W'){
      while(c[pos] == 'W') pos--;
      if(i >= pos) break;
      c[pos] = 'W';
      c[i] = 'R';
      ans++;
    }
  }
  cout << ans << endl;
}

