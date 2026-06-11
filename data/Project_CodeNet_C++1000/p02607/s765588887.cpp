#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 0;
  cin >> n;
  rep(i,0,n){
    int a;
    cin >> a;
    if(i%2 == 0 && a%2 == 1) ans++;
  }
  cout << ans << endl;
}