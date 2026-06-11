#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(long long i = a; i < b; i++)
#define dump(a) for(auto x : a) cout << x << " "; cout << "\n"
#define print(a) cout << a << "\n"
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr << #x << ": " << x << ", " << #y << ": " << y << "\n"
#define debug3(x,y,z) std::cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << "\n"

typedef long long ll;
using vi   = vector<int>;
using vll  = vector<long long>;
using vs   = vector<string>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<long long>>;
using vvs  = vector<vector<string>>;

int main() {
  string S,T;
  cin >> S >> T;

  int _min = 1000; // あり得る最大値
  rep(i,0,S.length()) {
    int diff = T.length();
    if (i + T.length() > S.length()) break;
    rep(j,0,T.length()) {
      if (T[j] == S[i + j]) {
        --diff;
      }
    }
    _min = min(diff,_min);
  }
  
  print(_min);
  return 0;
}