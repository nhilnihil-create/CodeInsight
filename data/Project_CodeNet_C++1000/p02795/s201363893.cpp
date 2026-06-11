#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  int mn = min(h,w);
  int mx = max(h,w);

  int cnt = 0;
  while(n>0){
    n -= mx;
    cnt++;
  }
  cout << cnt << endl;
}
