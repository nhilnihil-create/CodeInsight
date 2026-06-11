#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, m;
string s;

vector<int> v;
bool func(int now){
  if(now == 0){
    return true;
  }
  if(now < 0){
    return false;
  }
  for(int i = m; i >= 1; i--){
    int next = now - i;
    if(s[next] == '0'){
      v.push_back(next);
      if(func(next)) return true;
      v.pop_back();
    }
  }
  return false;

}



int main(){
  cin >> n >> m;
  cin >> s;
  int now = n;
  while(now > 0){
    bool ok = false;
    for(int i = m; i >= 1; i--){
      int next = now - i;
      if(next < 0) continue;
      if(s[next] == '1') continue;
      v.push_back(next);
      now = next;
      ok = true;
      break;
    }
    if(!ok){
      cout << -1 << endl;
      return 0;
    }
  }
  reverse(v.begin(), v.end());
  for(int i = 1; i <= v.size(); i++){
    if(i == v.size()) cout << n - v[i - 1] << " ";
    else cout << v[i] - v[i - 1] << " ";
  }
  cout << endl;
  return 0;
}
