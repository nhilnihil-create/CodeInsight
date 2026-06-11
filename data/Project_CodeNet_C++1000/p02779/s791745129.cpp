#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

void chmin(int &a, int b){
  if(a > b)
    a = b;
}
void chmax(int &a, int b){
  if(a < b)
    a = b;
}

void llchmin(ll &a, ll b){
  if(a > b)
    a = b;
}
void llchmax(ll &a, ll b){
  if(a < b)
    a = b;
}

int main(){
  int n;
  cin >> n;
  map<int, int> a;
  bool check = true;
  
  rep(i, 0, n){
    int t;
    cin >> t;
    if(a.count(t)){
      check = false;
      break;
    }
    else
      a[t] = 0;
  }
  
  if(check)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
  
}