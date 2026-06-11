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
  int tmp = 0;
  vector<int> data(N+1); 
  for(int i = 0; i < N-1 ; i++){
	cin >> tmp;
    data.at(tmp)++;
  }
  for(int i =1;i < data.size(); i++) cout << data.at(i) << endl;
}