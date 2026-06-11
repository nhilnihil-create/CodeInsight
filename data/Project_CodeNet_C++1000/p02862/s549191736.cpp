#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <ios>
#include <ctype.h>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <list>
#include <deque>
#include <time.h>
#include <random>
#include <iomanip>
#include <fstream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define pint pair<int,int>
#define SEG_LEN (1 << 20)
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
using Graph_weighted = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
  ll x,y;
  cin >> x >> y;
  if((x + y) % 3 != 0 || x == 0 || y == 0){
    cout << 0 << endl;
    return 0;
  }
  ll n = (x + y) / 3;
  x -= n;
  y -= n;
  if(x < 0 || y < 0){
    cout << 0 << endl;
    return 0;
  }
  ll a = 1,b = 1;
  REP(i,1,(x + y) + 1){
    a *= i;
    a %= INF;
  }
  REP(i,1,x + 1){
    b *= i;
    b %= INF;
  }
  REP(i,1,y + 1){
    b *= i;
    b %= INF;
  }
  cout << a * modinv(b,INF) % INF << endl;
  return 0;
}
 