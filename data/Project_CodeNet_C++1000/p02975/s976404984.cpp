#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  map<int,int> mp;
  bool zero = true;
  rep(i,n){
    int a; cin >> a;
    mp[a]++;
    if(a) zero = false;
  }
  bool ok = true;
  if(n % 3 != 0 || 3 < mp.size()) ok = false;
  for(auto x : mp) if(x.second%(n/3) != 0) ok = false;
  int check = 0;
  for(auto x : mp) rep(i,x.second/(n/3)) check ^= x.first;
  cout << (zero || ok && check==0 ? "Yes" : "No");
  cout << "\n";
  return 0;
}
