#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,m;
  string s;
  cin >> n >> m >> s;
  reverse(ALL(s));
  vector<int> v;
  vector<int> res;
  rep(i,n+1)if(s[i] == '0')v.push_back(i);
  int pos = 0;
  while(pos != n){
    int l = 0,r = v.size();
    while(r-l > 1){
      int mid = (l+r)/2;
      if(v[mid] <= pos+m)l = mid;
      else r = mid;
    }
    if(pos == v[l]){
      cout << -1 << endl;
      return 0;
    }
    res.push_back(v[l]-pos);
    pos = v[l];
  }
  for(int i = res.size()-1;i >= 0;i--)cout << res[i] << endl;




  return 0;
}
