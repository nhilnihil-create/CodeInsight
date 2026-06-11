#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <string.h>
#include <cstdarg>
 
using namespace std;
 
typedef long long ll;
 
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)
 
using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;
 
 
// Extended Print Func
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& input){
    os << "[ ";
    REP(i, input.size()){
        os << input[i];
        if (i < input.size()-1) { os << " "; }
    }
    os << " ]";
    return os;
}
void print() { std::cout << "\n"; }
template<class T, class... A> void print(const T& first, const A&... rest) { std::cout << first << " "; print(rest...); }
template<class... A> void print(const A&... rest) { print(rest...); }
 
ll A[1001][1001];
ll done[1001];
ll ne[1001];
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  memset(done,0,sizeof(done));
  ll N;
  cin >> N;
 
  REP(i,N){
      REP(j,N-1){
          cin >> A[i][j]; A[i][j]--;
          ne[i] = 0;
      }
  }
 
  
  ll day = 0;
  for(;;) {
      bool is_match = false;
      day++;
      REP(i,N){
          if (done[i] == day) continue;
          ll opp = A[i][ne[i]];
          if (done[opp] == day) continue;
          if (ne[i]<N-1 && ne[opp]<N-1 && i==A[opp][ne[opp]]) {
              is_match = true;
              ne[i]++; ne[opp]++;
              done[i]=day; done[opp]=day;
          }
      }
      if (!is_match) {
          day--;
          break;
      }
  }
 
  REP(i,N){
      if (ne[i] != N-1){
          cout << -1 << "\n";
          return 0;
      }
  }
  
  std::cout << day << "\n";  
  return 0;
}