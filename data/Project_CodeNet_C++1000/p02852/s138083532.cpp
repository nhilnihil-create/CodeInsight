// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
using namespace std;
using namespace std::chrono;
 

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int l[n + 1];
  l[n] = n;
  int st = 0, l_st = 0;
  for (int i = 1; i < n + 1; i++)
    if (s[i] == '0')
      st = 0;
    else
      st += 1, l_st = max(l_st, st);
  if (l_st >= m)
    cout << -1 << endl;
  else{
    for (int i = n; i >= 0; i--)
      if (s[i] == '0')
	l[i] = i;
      else
	l[i] = l[i + 1];
    int c = n;
    Vi ans;
    for (int i = 0; i < n + 1; i++){
      if (c - m < 0){
	ans.pb(c);
	break;
      }
      else{
	ans.pb(c - l[c - m]);
	c = l[c - m];
	if (c == 0)
	  break;
      }
    }
    for (int i = 0; i < ans.size(); i++)
      cout << ans[ans.size() - 1 - i] << " ";
    cout << endl;
  }
  
}
