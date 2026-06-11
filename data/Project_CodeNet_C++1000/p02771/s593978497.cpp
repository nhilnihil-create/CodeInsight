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
  int a, b, c;
  cin >> a >> b >> c;
  
  bool check = false;
  
  if(a == b || b == c || c == a){
    if(a ==b && b == c){}
    else
      check = true;
  }
  
  if(check)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
  
}