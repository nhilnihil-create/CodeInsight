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
  set<string> list;
  map<string, int> m;
  rep(i, 0, n){
    string s;
    cin >> s;
    list.insert(s);
    if(m.count(s))
      m[s]++;
    else
      m[s] = 1;
  }
  
  int mx = 0;
  
  auto itr1 = list.begin();
  rep(i, 0, list.size()){
    chmax(mx, m[*itr1]);
    itr1++;
  }
  
  auto itr2 = list.begin();
  rep(i, 0, list.size()){
    if(m[*itr2] == mx)
      cout << *itr2 << endl;
    itr2++;
  }
  
  return 0;
  
}