#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  int ans;

  if(b==1){
    cout << "0" << endl;return 0;
  }
  int test=a;
  ans = 1;
  while(test<b){
    test--;
    test+=a;
    ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}
