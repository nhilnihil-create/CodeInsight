#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <iomanip>
//#pragma GCC optimize("Ofast")  //デバッグ時にoptimized-outされて邪魔だった
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define floatprec(dig) fixed << setprecision(dig)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define invar(typ, var) typ var; cin >> var;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  //mod Kで考える
  invar(int, N); invar(ll, K);
  
  vll A(N);
  //累積和（mod K)
  vll acc(N+1);
  rep(i, N) {
    cin >> A[i];
    acc[i+1] = (acc[i] + A[i]) % K;
  }
  
  //S_i - i (mod K) ごとのiの数
  map<ll,ll> mp;
  ll ans = 0;
  
  //累積和は要素数が + 1
  //S[0] = 0なので，要素が常に満たされる．
  //和の数がK以上になったら，次から使われないので消す．
  queue<ll> que;
  for(int j=0; j<N+1; ++j) {
    //予めKを足す
    ll t = (acc[j] - j) % K;
    if(t < 0) t += K;
    
    ans += mp[t];
    mp[t]++;
    
    que.push(t);
    if(que.size() >= K) {
      mp[que.front()]--;
      que.pop();
    }
  }
  
  fin(ans);
}