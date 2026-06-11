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
  int N; cin >> N;
  vector<int> data(N+1);
  ll sum = 0;
  
  FOR(i,1,N+1){
    if(i % 3 == 0) data[i] = 0;
    else if(i % 5 == 0) data[i] = 0;
    else data[i] = 1;
  }
  FOR(i,1,N+1) sum += i * data[i];
  cout << sum << endl;
}