#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const int MAX = 10000;
static const ll INFTY = 1e12;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MRINF = 5000000000000000;

ll N, K;
vector<ll> A;
ll f(ll k){
  ll now = 0;
  REP(i, N){
     now += (A[i]-1)/k;
  }

  return now <= K;

}

int main() {

  cin >> N >> K;
  // vector<ll> A(N);
  REP(i, N){
    ll a; cin >> a;
    A.push_back(a);
  }

  ll s = 0;
  ll t = 1e10;
  ll ng = s, ok = t;
  while (ok - ng > 1) {
      ll mid = (ng + ok) / 2;
      if(f(mid)) ok=mid;
      else ng=mid;
      // (f(A, mid) ? ok : ng) = mid;
  }

  cout << ok << endl;


}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/