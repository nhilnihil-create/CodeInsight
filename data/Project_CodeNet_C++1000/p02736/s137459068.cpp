#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <time.h>
#include <assert.h>

using namespace std;

#define x first
#define y second
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = b-1; i >= a; i--)
#define DBG(x) cerr << (#x) << "=" << x << "\n";
#define ll long long
#define inf 1000000007
#define mod 1000000007
#define N 1000005

template<typename U, typename V> void Min(U &a, const V & b){if(a > b)a = b;}
template<typename U, typename V> void Max(U &a, const V & b){if(a < b)a = b;}
template<typename U, typename V> void add(U &a, const V & b){a = (a + b) % mod;}
template<typename U> U gcd(U a, U b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a >= b)return gcd(a % b, b);
    else return gcd(a, b % a);
}
int pow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}
int pow(int a, ll b, int c){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % c;
        a = 1LL * a * a % c;
        b >>= 1;
    }
    return ans;
}

char s[N];
int a[N], f[N];
int C(int a, int b){
  if(b == 0 || b == a)return 1;
  int k = f[a] - f[b] - f[a-b];
  return k > 0 ? 0 : 1;
}
int main(){
  int T, m, i, j, k, n, K;
  scanf("%d%s", &n, s);
  rep(i, 0, n-1){
    a[i] = abs(s[i] - s[i+1]);
  }
  n--;
  rep(i, 1, n+1){
    k = i;
    j = 0;
    while(k % 2 == 0)k /= 2, j++;
    f[i] = f[i-1] + j;
  }
  rep(it, 0, 2) {
    m = 0;
    k = 0;
    rep(i, 0, n)if(a[i] & 1){
      m += C(n-1, i);
      k++;
    }
    if(m & 1){
      if(it == 0)puts("1");
      else puts("2");
      return 0;
    }
    if(k){
      puts("0");
      return 0;
    }
    rep(i, 0, n)a[i] /= 2;
  }
  puts("0");
}
