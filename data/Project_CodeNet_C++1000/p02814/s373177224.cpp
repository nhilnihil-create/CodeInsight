#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC150D = Semi Common Multiple
// aiは必ず偶数のなので2で割れる
// 任意k（つまり正数列A全部）について、「akを2で割った数」の「奇数倍の数」を調べる
// 「最小半公倍数」が見つかれば、Mをそれをそれで割れば数を求められる
// 6 = 2*3, 10 = 2*5 →　2で割った数は3と5 → 15（最小半公倍数、5倍と3倍）
// 15の「奇数倍」が答え
// aiが2と6 → 1と3 → 最小半公倍数は3 →　1000000000/3 = 333333333
// 333333333 - (333333333/2) = 333333333 - 166666666 = 166666667
// 14, 22, 40 → 7, 11, 20;2^2*5 → 2の累乗があっても良いが全てのakで2の累乗の個数が同じ場合のときのみ
// ↑の判定式が必要

ll gcd(ll n, ll m){
  if(m == 0) return n;
  return gcd(m, n%m);
}

ll lcm(ll n, ll m){
  return n / gcd(n, m) * m;
}

int func(int n){
  int cnt = 0;
  while(n%2 == 0){
    n /= 2;
    cnt++;
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<int> A(N);
  REP(i, N){
    int a; cin >> a;
    if(a%2 == 1){
      cout << 0 << endl;
      return 0;
    }
    a /= 2;
    A[i] = a;
  }
  int cnt = func(A[0]);
  REPLL(i, N){
    if(cnt != func(A[i])){
      cout << 0 << endl;
      return 0;
    }
    // A[i] >>= cnt; // 2^cntは無駄なので消す
  }
  // M >>= cnt; // 2^cntは無駄なので消す
  ll g = 1;
  REP(i, N){
    g = lcm(g, A[i]);
    if(g > M){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << M/g - (M/g)/2 << endl;
}