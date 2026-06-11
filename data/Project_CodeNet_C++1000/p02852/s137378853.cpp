#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)

template<typename T>
using V = vector<T>;

template<typename T>
using V2 = V<V<T>>;

template<typename T>
using V3 = V<V2<T>>;

void solve(){
  int n, m; string s;
  cin >> n >> m >> s;
  {
    int l=0,r=0;
    for(;l<n+1;){
      while(l<=n && s[l]=='0'){++l;}
      r = l;
      while(r<=n && s[r]=='1'){++r;}
      if(r-l>=m){
        cout << -1 << endl;
        return;
      }
      l = r;
    }
  }
  vector<int> skr;
  skr.push_back(n);
  int pre=n,t = n;
  while(pre>0){
    t = max(0,pre-m);
    for(;t<pre;++t){
      if(s[t]=='0') break;
    }
    skr.push_back(t);
    pre = t;
  }
  for(int i=skr.size()-2; i>=0; --i){
    cout << skr[i] - skr[i+1] << " ";
  }
}

int main(void){
  solve();
  return 0;
}