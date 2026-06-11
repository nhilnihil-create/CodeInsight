#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans;
  if(a==c) ans = 0;
  else ans = 1;
  cout << ans << endl;
  return 0;
}
