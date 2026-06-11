#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  sort(all(a));
  sort(all(b));
  ll ans = 0;
  if(n%2){
    ans = b[n/2]-a[n/2]+1;
  }else{
    long double m = (a[n/2]+a[n/2-1])/2.0;
    long double M = (b[n/2]+b[n/2-1])/2.0;
    ans = (M-m)*2+1;
  }
  cout << ans;
  cout << endl;
  return 0;
}
