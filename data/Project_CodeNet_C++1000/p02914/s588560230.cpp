#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
// #define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int M = 1e9 + 7;
//__int128

template <const int n> class linear_base {
public:
	bitset<n> base[n];
	bool insert(bitset<n> vec) {
  	for(int i = n - 1; i >= 0; --i) {
  		if(vec[i]) {
  			if(base[i][i]) {
  				vec ^= base[i];
  			} else {
  				base[i] = vec;
  				return 1;
  			}
  		}
  	}
  	return 0;
	}

	bitset<n> getmax() {
		bitset<n> res;
		for(int i = n - 1; i >= 0; --i) {
			if(res[i] == 0 && base[i][i] > 0) {
				res ^= base[i];
			}
		}
		return res;
	}

};


signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  const int maxn = 1e5 + 5;
  bitset<64> a[maxn], sum;
  for(int i = 0; i < n; ++i) {
  	long long x;
  	cin >> x;
  	a[i] = x;
  	sum ^= a[i];
  }
  sum.flip();
  for(int i = 0; i < n; ++i) {
  	a[i] &= sum;
  }
  linear_base<64> s;
  for(int i = 0; i < n; ++i) {
  	s.insert(a[i]);
  }
  long long res = (s.getmax()).to_ullong();
  res *= 2;
  sum.flip();
  res += sum.to_ullong();
  cout << res << endl;
	return 0;
}