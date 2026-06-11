#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>

using namespace std;

#define INF 1000000007
using vi = vector<int>;
using vvi = vector< vector<int> >;
using pii = pair<int, int>;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  long long ans = 1;
  vi v(2*n);
  vi r;
  v[0] = 1;
  int now = 0;
  for(int i = 1; i < s.length(); i++){
    if(s[i] == s[i-1]){
      now = !now;
    }
    if(now){
      v[i] = v[i-1];
      ans *= v[i] - r.size();
      ans %= INF;
      r.push_back(i);
    }
    else{
      v[i] = v[i-1] + 1;
    }
  }
  for(int i = 0; i < n ; i++){
    ans *= (i+1);
    ans %= INF;
  }
  if(r.size() != n || s[0] == 'W' || s[2*n-1] == 'W') ans = 0;
  cout << ans << endl;
}
