#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> w(n);
  int sum1 = 0;
  rep(i,n){
    cin >> w.at(i);
    sum1 += w.at(i);
  }

  int ans = INF,sum2 = 0;
  rep(i,n){
    sum2 += w.at(i);
    sum1 -= w.at(i);
    ans = min(ans,abs(sum2-sum1));
  }

  cout << ans << endl;

}