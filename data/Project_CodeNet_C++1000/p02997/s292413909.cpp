#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

int main(){
  int n, k;
  cin>>n>>k;
  int l = (n-1)*(n-2) / 2;
  if(k > l) {
    std::cout << -1 << std::endl;
    return 0;
  } else {
    l -= k;
    int m = 0;
    vector<pair<int,int>> v;
    for(int i=2; i<=n; i++) {
      v.push_back(make_pair(1,i));
      m++;
    }
    bool f = false;
    for(int i=2; i<=n; i++) {
      if(f) break;
      for(int j=i+1; j<=n; j++) {
	if(l == 0) {
	  f = true;
	  break;
	}
	v.push_back(make_pair(i,j));
	l--;
	m++;
      }
    }
    std::cout << m << std::endl;
    rep(i,m) std::cout << v[i].first << ' ' << v[i].second << std::endl;
  }
  return 0;
}
