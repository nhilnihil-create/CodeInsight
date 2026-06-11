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
  string ans;
  if(500*n>=k) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}
