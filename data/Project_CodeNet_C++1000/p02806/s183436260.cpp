#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
  
  int n, time = 0;
  cin>>n;
  vector<string> s(n);
  vector<int> t(n);
  rep(i, n) {
    cin >> s.at(i) >> t.at(i);
    time += t.at(i);
  }
  string x;
  cin >> x;
  rep(i, n) {
    time -= t.at(i);
    if(s.at(i) == x) {
      break;
    }
  }
  cout << time << endl;
    
    return 0;
}