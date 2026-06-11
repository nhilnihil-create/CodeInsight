#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i=0; i+2<n; i++){
    if(s.substr(i, 3) == "ABC") ans++;
  }
  cout << ans << endl;
  return 0;
}
