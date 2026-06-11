#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
 
int main()
{
  int n;
  cin >> n;
  map<string, int> tl;
  vector<int> ti;
  int t_t = 0;
  REP(i,n)
  {
    string s;
    int t;
    cin >> s >> t;
    t_t += t;
    tl[s] = i;
    ti.push_back(t_t);
  }
  string x;
  cin >> x;
  
  cout << ti[n-1] - ti[tl[x]] << endl;
  return 0;
}