#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  
  vi a(n);
  vi s;
  rep(i,n) cin >> a.at(i);
  
  int r, l;
  {
    int v = 1;
    vi ord(n+1, -1);
    while (ord.at(v) == -1){
      ord.at(v) = s.size();
      s.push_back(v);
      v = a.at(v-1);
    }
   r = s.size() - ord.at(v);
   l = ord.at(v);
  }

  if (k < l) cout << s.at(k) << endl;
  else {
    k = (k - l) % r;
    cout << s.at(l+k) << endl;
  }
  return 0;
}
