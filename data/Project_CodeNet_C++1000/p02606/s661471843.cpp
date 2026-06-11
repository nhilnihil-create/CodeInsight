#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
  int L, R, d, count = 0;
  cin >> L >> R >> d;
  for (int i = L; i < R+1; i++){
    if (fmod(i,d) == 0){
      count += 1;
    }
  }
  cout << count << endl;
  return 0;
}