#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,x; cin >> n >> x;
  int cnt = 1;
  int d = 0;
  rep(i,n){
    int l; cin >> l;
    d+=l;
    if(d<=x) cnt++;
    else break;
  }
  /*vector<int> l(n);
  rep(i,n) cin >> l[i];

  int d = 0;
  int cnt = 0;
  rep(i,n){
    if(d<=x) cnt++;
    d+=l[i];
    }*/
  cout << cnt << endl;
  
  return 0;
}
