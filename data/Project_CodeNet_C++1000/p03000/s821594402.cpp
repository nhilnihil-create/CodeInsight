#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){
  int n,x; cin >> n >> x;
  vector<int> l(n);
  rep(i,n) cin >> l.at(i);

  int d = 0,ans = 1;

  for(int i=0;i<n;i++){
    d+=l.at(i);
    if(d>x) break;
    ans++;
  }

  cout << ans << endl;
}
