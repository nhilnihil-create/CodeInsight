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
  long long base[64] = {0};
  for(int i = 0; i < n; ++i) {
  	long long t = a[i].to_ullong();
  	for(int j = 60; j >= 0; --j) {
  		if(t >> j & 1) {
  			if(base[j]) {
  				t ^= base[j];
  			} else {
  				base[j] = t;
  				break;
  			}
  		}
  	}
  }
  long long res = 0;
  for(int i = 63; i >= 0; --i) {
  	if(base[i] && !(res >> i & 1)) {
  		res ^= base[i];
  	}
  }
  res <<= 1;
  sum.flip();
  res += sum.to_ullong();
  cout << res << endl;
	return 0;
}