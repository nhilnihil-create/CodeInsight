#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
  int n, k;
  cin >> n >> k;
  int m = ((n-1)*(n-2))/2;
  
  if(k > m)
  {
    cout << "-1" << endl;
    return 0;
  }
  
  vector<P> res;
  rep(i, n-1) res.emplace_back(P(i, n-1));
  
  int num = -1;
  while((int)res.size()-n+1+k < m)
  {
    num++;
    int a = num/(n-1), b = num%(n-1);
    if(a >= b) continue;
    res.emplace_back(P(a, b));
    
  }
  
  cout << (int)res.size() << endl;
  for(auto x : res) cout << x.first+1 << " " << x.second+1 << "\n";

  return 0;
}