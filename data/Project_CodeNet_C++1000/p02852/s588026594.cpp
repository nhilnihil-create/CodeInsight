#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector < ll > v;
  for(int i = 0; i <= n; i++){
    if(s[i] == '0') v.push_back(i);
  }

  vector < ll > ans;
  for(int i = 0; i <= n; i++){
    if(i == n) break;
    auto it = upper_bound(v.begin(), v.end(), i + m);
    --it;
    if(*it == i){
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(*it - i);
    i = *it - 1;
  }
  reverse(ans.begin(), ans.end());
  for(auto i : ans) cout << i << " ";
  cout << endl;
}
