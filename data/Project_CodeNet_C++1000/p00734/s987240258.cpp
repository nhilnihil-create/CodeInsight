#include <bits/stdc++.h>
#ifdef dbg
#include "./printer.hpp"
#else
#define dump(x) void(0)
#endif

#define MOD 1000000007
#define INF 
using namespace std;
#define ll long long
inline long  toInt(string s) {long  v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

int main(){
  ll n,m;
  while(cin >> n >> m && (n+m)){
    vector<ll> a(n);
    vector<ll> b(m);
    unordered_set<ll> bs;
    ll suma = 0, sumb = 0;
    for(ll i = 0; i < n; i++){
      cin >> a[i];
      suma += a[i];
    }
    for(ll i = 0; i < m; i++){
      cin >> b[i];
      bs.insert(b[i]);
      sumb += b[i];
    }
    for(ll i = 0; i < n; i++){
      if((sumb - suma + 2 * a[i]) % 2 == 0 && bs.find((sumb - suma + 2 * a[i]) / 2) != bs.end()){
	cout << a[i] << ' ' << (sumb - suma + 2 * a[i]) / 2 << endl;
	break;
      }
      if(i == n-1){
	cout << -1 << endl;
      }
    }

    // suma - a[i] + x == sumb - x + a[i]
    
  }

}