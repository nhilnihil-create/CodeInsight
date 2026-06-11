#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  int s[3];
  for(int i=0; i<3; i++) cin >> s[i];
  string t;
  cin >> t;
  int ans = 0;
  for(int i=0; i<n; i++){
    if(i/k){
      if(t[i-k]==t[i]){
        t[i] = 'x';
        continue;
      }
      if(t[i]=='r') ans += s[2];
      else if(t[i]=='s') ans += s[0];
      else ans += s[1];
    }else{
      if(t[i]=='r') ans += s[2];
      else if(t[i]=='s') ans += s[0];
      else ans += s[1];
    }
  }
  cout << ans << endl;
  return 0;
}
