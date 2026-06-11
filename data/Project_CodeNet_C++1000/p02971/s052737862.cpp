#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<pair<int,int>> a(n);
  rep(i,n){
    int p;
    cin >> p;
    a[i] = make_pair(p,i);
  }

  sort(a.begin(),a.end());
  rep(i,n){
    if(a[n-1].second == i){
      cout << a[n-2].first << endl;
    }
    else{
      cout << a[n-1].first << endl;
    }
  }
  
  return 0;
}
