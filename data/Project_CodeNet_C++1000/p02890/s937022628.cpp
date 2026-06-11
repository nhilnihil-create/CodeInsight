#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)3e5 + 9;
int cnt[N];
int d[N];
int pf[N];
int suf[N];
int f[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    cnt[x] ++ ;
  }
  for(int i = 1; i <= n; i ++ ) d[cnt[i]] ++ ;
  for(int i = 1; i <= n; i ++ ){
    pf[i] = (pf[i - 1] + i * d[i]);
  }
  for(int i = n; i >= 1; i -- ){
    suf[i] = (suf[i + 1] + d[i]);
  }
  for(int i = 1; i <= n; i ++ ){
    f[i] = (pf[i]/i) + suf[i+1];
  }
  int p = n;
  for(int i = 1; i <= n; i ++ ){
    while(p > 0 && f[p] < i){
      p -- ;
    }
    cout << p << "\n";
  }
  return 0;
}