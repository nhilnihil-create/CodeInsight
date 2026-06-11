#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

vi a;

void chmax(int &a, int b){
  if(a < b)
    a = b;
}

bool is_ok(int x, int k){
  int sum = 0;
  rep(i, 0, a.size()){
    sum += (a[i] + (x-1))/x -1;
  }
  if(k >= sum)
    return true;
  else
    return false;
}

int binary_search(int key, int amax){
  int ng = 0;
  int ok = amax;
  
  while(abs(ok-ng) > 1){
    int mid = (ok + ng)/2;
    
    if(is_ok(mid, key))
      ok = mid;
    else
      ng = mid;
  }
  
  return ok;
}

int main(){
  int n, k;
  cin >> n >> k;
  int amax = 0;
  rep(i, 0, n){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    chmax(amax, tmp);
  }
  
  int ans = binary_search(k, amax);
  
  cout << ans << endl;
  
  return 0;
  
}