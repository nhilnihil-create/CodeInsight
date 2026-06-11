#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int n,k;
  cin >> n >> k;
  if(k>(n-1)*(n-2)/2){ cout << -1 << endl; return 0; }
  int cnt = (n-1)*(n-2)/2;
  cnt -= k;
  int ans = n-1 + cnt;
  vector<int> v[n];
  rep(i,n-1){ v[0].emplace_back(i+1); }
  for(int i=1; i<n && cnt>0; i++){
    for(int j=i+1; j<n && cnt>0; j++){
      v[i].emplace_back(j);
      cnt--;
    }
  }

  cout << ans << endl;
  rep(i,n)for(auto it:v[i]){
    cout << i+1 << " " << it+1 << endl;
  }
  return 0;
}