#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

bool is_prime(int64_t x) {
  for(int64_t i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

int main(void){
    int x;
    cin >> x;
    while(1){
        if(is_prime(x)){
            cout << x;
            return 0;
        }else x++;
    }

}