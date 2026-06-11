#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int n, m, v, p;
int a[N];

bool can(int k){  
  int tot = 0;
  for(int i = 1; i <= n; i ++ ){
    if(a[i] > a[k]){
      tot ++ ;
    }
  }
  if(tot < p) return true;
  int nw = a[k] + m;
  tot = 0;
  ll votes = m * 1ll * (v-1);
  for(int i = n; i >= 1; i --){
    if(a[i] > nw){
      tot ++ ;
      votes -= m;
    }
    else if(i != k){
      if(tot < p-1){
        tot ++ ;
        votes -= m;
      }
      else{
        votes -= min(m, nw - a[i]);
      }
    }
  }
  if(tot >= p || votes > 0) return false;
  return true;
}

int main(){
  fastIO;
  cin >> n >> m >> v >> p;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  sort(a + 1,a + n + 1);
  int l = 1, r = n;
  int mid;
  while(l < r){ // nothing beats a good ol' bin search
    mid = (l + r) / 2;
    if(can(mid)){
      r = mid;
    }
    else{
      l = mid + 1;
    }
  }
  cout << n - r + 1 << "\n";
  return 0;
}