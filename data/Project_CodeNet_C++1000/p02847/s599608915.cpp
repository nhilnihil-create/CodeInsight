#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;
  vector<string> vec={"SUN","MON","TUE","WED","THU","FRI","SAT" };
  map<string, int> m;
  rep(i, vec.size()) {
    m[vec[i]] = 7 - i;
  }
  cout << m[s] << endl;
  
  return 0;
}
