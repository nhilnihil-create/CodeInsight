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
  int tmp = 1, cnt = 0;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(a==tmp){
      tmp++;
      cnt++;
    }
  }
  int ans;
  if(cnt==0) ans = -1;
  else ans = n-cnt;
  cout << ans << endl;
  return 0;
}
