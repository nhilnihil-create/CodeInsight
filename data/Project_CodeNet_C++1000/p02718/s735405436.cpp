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
  int N,M; cin >> N >> M;
  int ans = 0, sum = 0;
  vector<int> A(N); 
  REP(i,N){
    cin >> A[i];
    sum += A[i];
  }
  REP(i,N){
    if(A[i] * 4 * M >= sum) ans++;
  }
  if(ans >= M)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}