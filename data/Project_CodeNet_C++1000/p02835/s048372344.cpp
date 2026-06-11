#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  vector<int> a(3);rep(i,3) cin >> a[i];
  int test = 0;
  rep(i,3) test+=a[i];
  if(test>=22) cout << "bust" << endl;
  else cout << "win" << endl;
    
  return 0;
}
