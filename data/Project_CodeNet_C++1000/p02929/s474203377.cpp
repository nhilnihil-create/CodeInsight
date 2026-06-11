#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i = 0; i < (int64_t)(n); i++)

int64_t myadd(int64_t a, int64_t b) {
  int64_t a_ = a % 1000000007;
  int64_t b_ = b % 1000000007;
  return ( a_ + b_ ) % 1000000007;
}

int64_t myprod(int64_t a, int64_t b) {
  int64_t a_ = a % 1000000007;
  int64_t b_ = b % 1000000007;
  return ( a_ * b_ ) % 1000000007;
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
    vector<int64_t> r_index(0);
    int64_t l = 0;
    int64_t r = 0;
    vector<int64_t> l_count(2*N);
    vector<int64_t> r_count(2*N);
    bool is_left = true;
    char pre_c = '_';
    char c;
    rep(i,2*N) {
      c = S.at(i);
      if ( c == pre_c ) {
        is_left = !is_left;
      }
      l_count.at(i) = l;
      r_count.at(i) = r;
      if ( is_left ) {
        l++;
      }
      else {
        r_index.push_back(i);
        r++;
      }
  //    cout << "(" << l << "," << r << ")" << endl;
      pre_c = c;
    }
    if ( l == r ) {
      int64_t base = 1;
      for(auto i : r_index) {
        base = myprod(base, l_count.at(i) - r_count.at(i));
      }
      answer = myprod(base, myfact(N));
    }
    else {
      answer = 0;
    }
  }
  //output
  cout << answer << endl;
}