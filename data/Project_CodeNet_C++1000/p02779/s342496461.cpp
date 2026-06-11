#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  string s = "YES";
  map<int, int> mp;
  rep(i, n){
    int x;
    cin >> x;
    mp[x]++;
    if(mp[x] > 1) s = "NO";
  }
  cout << s << endl;

  return 0;
}
