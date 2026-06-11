#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  int cnt = 0, ban = 1;
  rep(i,n){
    int a;
    cin >> a;
    if(a != ban) cnt++;
    else ban ++;
  }
  if(cnt == n) cout << -1 << endl;
  else cout << cnt << endl;
}
