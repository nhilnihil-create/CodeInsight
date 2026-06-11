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
  int n, r;
  cin >> n >> r;
  
  if(n >= 10)
    cout << r << endl;
  else
    cout << r+ 100*(10-n) << endl;
  
  return 0;
  
}