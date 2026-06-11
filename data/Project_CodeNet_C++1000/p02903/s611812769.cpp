#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  REP(i,H){
    REP(j,W){
      if((i<B&&j<A)||(i>=B&&j>=A)){
        cout << 0; 
      }else{
        cout << 1;
      }
    }
    cout << endl;
  }

}