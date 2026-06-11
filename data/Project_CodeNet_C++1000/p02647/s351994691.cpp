#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1e9+7;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
typedef pair<ll, ll> pll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  

  rep(i, k){
    vector<int> b(n, 0);
    for (int i=0; i < n; i++){
      int l = max(0, i-a[i]);
      int r = min(n-1, i+a[i]);

      b[l]++;
      if(r+1 < n) b[r+1]--;
    }
    rep(i, n-1) b[i+1] += b[i];

    bool same = true;
    rep(i, n){
      if(a[i] != b[i]) same = false;
    }
    a = b;
    if(same) break;
  }

  rep(i, n){
    cout << a[i] << endl;
  }
}
