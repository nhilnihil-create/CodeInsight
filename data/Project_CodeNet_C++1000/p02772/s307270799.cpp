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
  vi a(n);
  rep(i, 0, n)
    cin >> a[i];
  
  bool check = true;
  
  rep(i, 0, n){
    if(a[i] %2 == 0){
      if(a[i] %3 != 0 && a[i] %5 != 0){
        check = false;
        break;
      }
    }
  }
  
  if(check)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
  
  return 0;
  
}