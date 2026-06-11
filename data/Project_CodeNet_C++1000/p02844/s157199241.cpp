#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

// int ctoi(const char c){
//   if('0' <= c && c <= '9') return (c-'0');
//   return -1;
// }

// int gcd(int a, int b){
//   int ma = max(a,b);
//   int mi = min(a,b);
//   if(mi == 0) return ma;

//   return gcd(mi, ma%mi);
// }
int main(){
  int ans = 0;
  int N;
  string S;
  cin >> N >> S;
  for(int i=0; i<=999; ++i){
    std::ostringstream sout;
    sout << setfill('0') << setw(3) << i;
    string str = sout.str();
    int flg = 0;
    for(int j=0; j<N; ++j){
      if(S[j]==str[flg]) ++flg;
      if(flg==3){
        ++ans;
        break;
      }
    }
  }
  cout << ans << endl;
}
