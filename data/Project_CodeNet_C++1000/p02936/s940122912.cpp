#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> ki[n];
  int ki_p[n] = {0};
  REP(i,0,n-1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
  }

  REP(i,0,q){
    int a, b;
    cin >> a >> b;
    a--;
    ki_p[a] += b;
  }

  queue<pair<int,int>> aa;
  aa.push({0,-1});
  while(aa.size()>0){
    int i = aa.front().first;
    for(int j:ki[i]){
      if(aa.front().second == j)continue;
      ki_p[j] += ki_p[i];
      aa.push({j,i});
    }
    aa.pop();
  }
  
  REP(i,0,n){
    cout << ki_p[i] << " ";
  }
  cout << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}