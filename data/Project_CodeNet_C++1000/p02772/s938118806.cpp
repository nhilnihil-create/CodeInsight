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
  int n; cin >> n;
  vector<int> data(n); REP(i,n) cin >> data[i];
  bool flag = true;
  REP(i,n){
    if(data[i] % 2 == 0){
      if(data[i] % 3 != 0 && data[i] % 5 != 0){
        flag = false;
        break;
      }
    }
  }
  if(flag)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
}