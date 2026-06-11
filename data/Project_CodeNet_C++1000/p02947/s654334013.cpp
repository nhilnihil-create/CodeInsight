#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int k, x;
  int n;
  cin >> n;
  vector<string> vs;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vs.push_back(s);
  }
  sort(vs.begin(), vs.end());
  ll ans = 0;
  ll i = 0, j = 0;
  while(i<n&&j<n){
    while(vs[i]==vs[j]){
      j++;
      if(j==n) break;
    }
    ans += (j-i)*(j-i-1)/2;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
