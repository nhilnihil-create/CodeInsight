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
long long n, k;
long long a[200005];

bool check(int x){
  int cnt = 0;
  for (int i=0; i<n; i++){
    cnt += (a[i] - 1) / x;
  }
  if(cnt <= k) return true;
  else return false;
}

int main() {
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];

  long long left = 0;
  long long right = INF;

  while(right - left > 1){
    
    long long mid = (left + right) / 2;
    
    if(check(mid))right = mid;
    else left = mid;
    // cout << left << " " << right << endl;
  }
  cout << right << endl;
}
