#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i = 0; i < (int64_t)(n); i++)
#define mod(a) a % 1000000007;

int64_t myadd(int64_t a, int64_t b) {
  int64_t a_ = mod(a);
  int64_t b_ = mod(b);
  return mod( a_ + b_ );
}

int64_t myprod(int64_t a, int64_t b) {
  int64_t a_ = mod(a);
  int64_t b_ = mod(b);
  return mod( a_ * b_ );
}

int64_t myfact(int64_t n) {
  if ( n == 1 ) {
    return 1;
  }
  return myprod(n, myfact(n-1));
}

int main() {
  //input
  int64_t N;
  string S;
  cin >> N >> S;
  //calc
  int64_t answer;
  
  if ( S.at(0) == 'W' ) {
    answer = 0;
  }
  else {
    int64_t base = 1;
    int64_t l = 0;
    int64_t r = 0;
    bool is_left = true;
    char pre_c = '_';
    char c;
    rep(i,2*N) {
      c = S.at(i);
      if ( c == pre_c ) {
        is_left = !is_left;
      }
      if ( is_left ) {
        l++;
      }
      else {
        base = myprod(base, l-r);
        r++;
      }
  //    cout << "(" << l << "," << r << ")" << endl;
      pre_c = c;
    }
    if ( l == r ) {
      answer = myprod(base, myfact(N));
    }
    else {
      answer = 0;
    }
  }
  //output
  cout << answer << endl;
}
