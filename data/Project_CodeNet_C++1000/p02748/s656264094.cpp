#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  REP(i, A) cin >> a[i];
  vector<int> b(B);
  REP(i, B) cin >> b[i];
  vector<vector<int>> x(M,vector<int>(3));
  REP(i, M){
    REP(j, 3){
      cin >> x.at(i).at(j);
    }
  }
  
  int MIN = INF;
  REP(i,M){
    MIN = min(MIN,a.at(x.at(i).at(0)-1)+b.at(x.at(i).at(1)-1)-x.at(i).at(2));
  }

  sort(ALL(a));
  sort(ALL(b));
  MIN = min(MIN,a.at(0)+b.at(0));
  cout << MIN << endl;
}