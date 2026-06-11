#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int h, n;
  cin >> h >> n;
  int ans=h/n;
  if(h%n) ans++;
  cout << ans << endl;
  return 0;
}
