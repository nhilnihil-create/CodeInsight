#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  int keta = 0;

  int test = n;
  while(test>0){
    test /= 10;
    keta++;
  }
  
  int ans = 0;
  switch(keta){
  case 1:
    for(int i = 1;i<=n;i++) ans++;
    break;
  case 2:
    ans = 9;
    break;
  case 3:
    ans = 9;
    for(int i = 100;i<=n;i++) ans++;
    break;
  case 4:
    ans = 9+900;
    break;
  case 5:
    ans = 9+900;
    for(int i = 10000;i<=n;i++) ans++;
    break;
  case 6:
    ans = 9+900+90000;
  }

  cout << ans << endl;
  
  return 0;
}
